/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:48:44 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/27 15:21:56 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*rtn;
	char	*cpy;
	size_t	i;

	i = 0;
	rtn = (char *)dst;
	cpy = (char *)src;
	while (i < len)
	{
		rtn[i] = cpy[i];
		i++;
	}
	return (dst);
}
