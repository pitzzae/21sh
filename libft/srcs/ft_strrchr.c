/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:06:12 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/30 15:59:13 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t	size;

	size = ft_strlen(src);
	if (c == 0)
		return ((char *)&src[size]);
	while (src[size] != (char)c && size != 0)
	{
		size--;
		if (src[size] == (char)c)
			return ((char *)&src[size]);
	}
	return (NULL);
}
