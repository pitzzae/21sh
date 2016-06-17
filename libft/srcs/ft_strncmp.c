/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:18:39 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/30 14:26:00 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[i] && i < (length - 1))
	{
		if (s1[i] == s2[i])
			j++;
		else
			i = length;
		i++;
	}
	if (length > 0)
		return ((unsigned char)s1[j] - (unsigned char)s2[j]);
	else
		return (0);
}
