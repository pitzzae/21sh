/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 00:13:14 by gtorresa          #+#    #+#             */
/*   Updated: 2016/01/21 00:13:18 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	**ft_tab_realloc(char **data, size_t size)
{
	char		**tmp;
	size_t		pos;

	pos = 0;
	tmp = (char**)malloc(sizeof(tmp) * size);
	if (tmp)
	{
		while (pos < size - 1 && data[pos])
		{
			tmp[pos] = ft_strdup(data[pos]);
			free(data[pos]);
			pos++;
		}
		free(data);
		return (tmp);
	}
	return (NULL);
}
