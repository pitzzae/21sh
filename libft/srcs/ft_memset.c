/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:51:29 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/27 15:15:21 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memset(void *b, int c, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)b;
	while (i < size)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
