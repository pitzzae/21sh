/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:40:38 by gtorresa          #+#    #+#             */
/*   Updated: 2015/12/04 01:31:08 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*ft_revstr(char *str)
{
	char	*dst;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(str);
	dst = ft_strdup(str);
	while (i > 0)
	{
		dst[j] = str[i - 1];
		j++;
		i--;
	}
	dst[j] = '\0';
	free(str);
	return (dst);
}

static int		get_len(const int n)
{
	int			i;
	long int	r;

	i = 1;
	r = n;
	while (r / 10 > 0)
	{
		i++;
		r = r / 10;
	}
	return (i);
}

static char		*ft_itoacal(long int n, char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (str);
	while (n)
	{
		str[i++] = (n % 10) + 48;
		n = n / 10;
	}
	return (ft_revstr(str));
}

char			*ft_itoa(long int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strnew(1);
		if (str == NULL)
			return (str);
		str[0] = '0';
		return (str);
	}
	else if (n < 0)
	{
		str = ft_strnew(1);
		if (str == NULL)
			return (NULL);
		n = -n;
		str[0] = '-';
		return (ft_strjoin_free(str, ft_itoacal(n, ft_strnew(get_len(n))), 3));
	}
	else
	{
		str = ft_strnew(get_len(n));
		return (ft_itoacal(n, str));
	}
}
