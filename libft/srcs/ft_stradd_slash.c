/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:12:32 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:39:05 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_init_new_str(char **str, char c)
{
	char	*out;
	int		i;

	i = ft_strocur(str[0], c);
	out = ft_strnew(ft_strlen(str[0]) + i + 1);
	if (!out)
		return (NULL);
	ft_strcpy(out, str[0]);
	return (out);
}

void		ft_load_str(char **str, int i)
{
	char	tmp;
	int		j;

	j = 0;
	while (str[0][i + j + 1])
	{
		tmp = str[0][i + j];
		str[0][i + j] = '\\';
		str[0][i + j + 1] = tmp;
		j++;
	}
}

size_t		ft_stradd_slash(char **str, char c)
{
	char	*out;
	int		i;

	i = 0;
	out = ft_init_new_str(str, c);
	if (!out)
		return (0);
	while (str[0][i])
	{
		if (str[0][i] == c)
		{
			ft_load_str(&str[0], i);
		}
		i++;
	}
	free(str[0]);
	str[0] = out;
	return (ft_strlen(str[0]));
}
