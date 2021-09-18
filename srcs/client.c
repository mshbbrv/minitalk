/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:38:13 by thjonell          #+#    #+#             */
/*   Updated: 2021/09/18 12:38:16 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "../libft/libft.h"

static int g_wait = 1;

void	signals_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		write(STDOUT_FILENO, "server received data\n", 21);
		exit(0);
	}
	g_wait = 0;
}

void	my_pause(void)
{
	while (g_wait)
		;
	g_wait = 1;
}

void	send_char(char c, int server_pid)
{
	int	counter;

	counter = 0;
	while (counter < 8)
	{
		if (c >> counter & 1)
		{
			if (kill(server_pid, SIGUSR2) == -1)
			{
				write(STDERR_FILENO, "kill error\n", 11);
				exit(0);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR1) == -1)
			{
				write(STDERR_FILENO, "kill error\n", 11);
				exit(0);
			}
		}
		my_pause();
		counter++;
	}
}

void	send_string_to_server(int server_pid, char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		send_char(string[i], server_pid);
		i++;
	}
	send_char(0, server_pid);
}

int		main(int ac, char *av[])
{
	pid_t	server_pid;
	char	*string;

	if (ac == 3)
	{
		signal(SIGUSR1, signals_handler);
		signal(SIGUSR2, signals_handler);
		server_pid = ft_atoi(av[1]);
		string = av[2];
		send_string_to_server(server_pid, string);
	}
	else
		write(STDERR_FILENO, "wrong number of arguments\n", 26);
	return (0);
}
