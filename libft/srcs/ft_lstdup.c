/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 21:27:38 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/24 15:12:04 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	del(void *c, size_t d)
{
	free(c);
	(void)d;
}

t_list		*ft_lstdup(const t_list *lst, size_t ln)
{
	t_list	*dst;
	t_list	*tmp;
	t_list	*tmp2;
	size_t	i;

	i = 1;
	dst = ft_lstnew(lst->content, ft_strlen(lst->content) + 1);
	dst->select = lst->select;
	tmp = dst;
	while (i < ln && lst != NULL)
	{
		lst = lst->next;
		dst->next = NULL;
		tmp2 = ft_lstnew(lst->content, ft_strlen(lst->content) + 1);
		tmp2->select = lst->select;
		ft_lstaddend(&dst, tmp2);
		ft_lstdelone(&tmp2, del);
		dst = dst->next;
		i++;
	}
	return (tmp);
}
