/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlocur.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 16:19:57 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/24 15:04:17 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_strlocur(char *str, char c)
{
	int		i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (-1);
}
