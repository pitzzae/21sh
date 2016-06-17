/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strocur_slash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:06:03 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/08 16:06:05 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_strocur_slash(char *str, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == c)
			j++;
		else
		{
			if (str[i] == c && str[i - 1] != '\\')
				j++;
		}
		i++;
	}
	return (j);
}
