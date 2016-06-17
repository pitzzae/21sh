/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 17:09:45 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:39:29 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			**ft_tabdup(char **tab)
{
	char		**out;
	int			len;

	len = 0;
	while (tab[len] != 0)
		len++;
	out = (char**)malloc(sizeof(out) * (len + 1));
	if (!out)
		return (NULL);
	len = 0;
	while (tab[len] != 0)
	{
		out[len] = ft_strdup(tab[len]);
		len++;
	}
	out[len] = (NULL);
	return (out);
}
