/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strduo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:02:24 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/01 18:10:58 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;

	if (!(str = (char *)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_memcpy(str, s1, ft_strlen(s1) + 1));
}
