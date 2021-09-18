/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 20:39:33 by thjonell          #+#    #+#             */
/*   Updated: 2020/11/02 20:42:36 by thjonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lstnew;

	if (!(lstnew = (t_list *)malloc((sizeof(t_list)))))
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}
