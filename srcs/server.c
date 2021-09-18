/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:38:22 by thjonell          #+#    #+#             */
/*   Updated: 2021/09/18 12:38:24 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"

void	signal_handler(int signum, siginfo_t *info, void *con)
{
	static char	c = 0;
	static int	i = 0;

	(void)con;
	if (signum == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			write(STDOUT_FILENO, &c, 1);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int		main(void)
{
	pid_t				pid;
	struct sigaction	sa;
	int					true;

	true = 42;
	pid = getpid();
	if (pid < 0)
	{
		write(STDERR_FILENO, "pid error\n", 10);
		exit(0);
	}
	write(STDOUT_FILENO, "my pid is ", 10);
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		true = 42;
}
