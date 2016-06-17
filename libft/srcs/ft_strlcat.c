/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:06:12 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/28 17:40:57 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t length)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	ret;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	ret = dst_len + src_len;
	if (length < dst_len)
	{
		return (length + src_len);
	}
	if ((size_t)ft_strlen(dst) < length)
	{
		while (dst_len < (length - 1))
		{
			dst[dst_len++] = src[i++];
		}
	}
	if (length > dst_len)
		dst[dst_len] = 0;
	return (ret);
}
