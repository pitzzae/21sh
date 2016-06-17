/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:47:58 by gtorresa          #+#    #+#             */
/*   Updated: 2015/12/05 18:21:19 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strsub_free(char *s, unsigned int start, size_t len, int f)
{
	char			*dst;
	unsigned int	i;

	i = 0;
	dst = (char *)malloc((len + 1) * sizeof(*dst));
	if (dst == NULL)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	if (f == 1)
		free(s);
	return (dst);
}
