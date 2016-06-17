/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:33:24 by gtorresa          #+#    #+#             */
/*   Updated: 2015/12/03 16:58:37 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(char *src)
{
	int		a;
	int		b;
	char	*str2;

	a = ft_strlen(src);
	str2 = (char *)malloc(sizeof(char) * (a + 1));
	b = 0;
	while (b < a)
	{
		str2[b] = src[b];
		b++;
	}
	str2[b] = '\0';
	return (str2);
}
