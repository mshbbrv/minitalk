/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:37:10 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/01 22:00:17 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!(str = malloc(len + 1)) || !s)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
