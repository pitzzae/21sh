/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:25:14 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/29 17:04:09 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;

	nlst = ft_lstnew(lst->content, lst->content_size);
	nlst = f(lst);
	if (lst->next)
	{
		nlst->next = ft_lstmap(lst->next, f);
	}
	return (nlst);
}
