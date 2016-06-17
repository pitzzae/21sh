/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 21:01:41 by gtorresa          #+#    #+#             */
/*   Updated: 2015/12/10 21:04:29 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*print_str(char **str, char *ret)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			ret[k] = str[i][j];
			j++;
			k++;
		}
		free(str[i]);
		ret[k++] = '\n';
		i++;
	}
	free(str);
	return (ret);
}

char	*ft_tab_to_str(char **str)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			j++;
			k++;
		}
		i++;
		k++;
	}
	ret = (char *)malloc(sizeof(ret) * k);
	ret = print_str(str, ret);
	return (ret);
}
