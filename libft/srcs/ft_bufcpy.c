/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/04 19:19:34 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/24 14:59:48 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_bufcpy(char *dest, const char *src, int size)
{
	int i;

	i = 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
