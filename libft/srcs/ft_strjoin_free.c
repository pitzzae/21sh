/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 18:19:50 by gtorresa          #+#    #+#             */
/*   Updated: 2015/12/16 20:30:16 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int fre)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (fre == 1)
		free(s1);
	if (fre == 2)
		free(s2);
	if (fre == 3)
	{
		free(s1);
		free(s2);
	}
	return (str);
}
