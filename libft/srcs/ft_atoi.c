/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:33:03 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/28 17:35:35 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_atoi_neg(const char *str, int i)
{
	int result;

	result = 0;
	i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result *= 10;
		result += (int)str[i] - 48;
		i++;
	}
	return (-1 * (result));
}

int			ft_atoi(const char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]) == 1)
		result = ft_atoi_neg(str, i);
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result *= 10;
		result += (int)str[i] - 48;
		i++;
	}
	return (result);
}
