/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:47:34 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/29 14:09:47 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list		*ft_lstnew(void const *c, size_t cz)
{
	t_list	*list;

	list = (t_list*)malloc(sizeof(*list));
	if (list != NULL)
	{
		if (c == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
			list->select = 0;
			list->valid = 0;
		}
		else
		{
			list->content = (void *)malloc(cz * (sizeof(*c)));
			ft_memcpy(list->content, c, cz);
			list->content_size = cz;
			list->select = 0;
			list->valid = 0;
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
