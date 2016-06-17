/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:49:04 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/27 15:52:12 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if ((*(char *)s1++ = *(char *)s2++) == (char)c)
			return (s1);
		i++;
	}
	return (NULL);
}
