/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:13:29 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/24 15:03:36 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_strisprint(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
