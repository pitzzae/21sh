/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 00:12:34 by gtorresa          #+#    #+#             */
/*   Updated: 2015/12/17 00:12:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list		*ft_lstnew_free(void *c, size_t cz)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(*list));
	if (list != NULL)
	{
		if (c == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			list->content = (void *)malloc(cz * (sizeof(*c)));
			ft_memcpy(list->content, c, cz);
			free(c);
			list->content_size = cz;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
