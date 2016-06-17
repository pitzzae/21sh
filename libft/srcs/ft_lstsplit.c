/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:05:07 by gtorresa          #+#    #+#             */
/*   Updated: 2015/12/01 17:01:07 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstsplit(char const *s, char c)
{
	t_list	*lst;
	char	**ssplit;
	size_t	i;

	i = 0;
	ssplit = ft_strsplit(s, c);
	lst = ft_lstnew(ssplit[i], ft_strlen(ssplit[i]));
	if (lst == NULL)
		return (NULL);
	while (ssplit[i + 1])
	{
		i++;
		ft_lstaddend(&lst, ft_lstnew(ssplit[i], ft_strlen(ssplit[i])));
	}
	return (lst);
}
