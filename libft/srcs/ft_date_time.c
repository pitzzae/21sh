/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_date_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 11:33:31 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/24 15:00:05 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <time.h>

static void	ft_free_tmp(char **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp[3]);
	free(tmp[4]);
	free(tmp[5]);
	free(tmp);
}

static void	get_hms(char *hms, t_date *d)
{
	char	**tmp;

	tmp = ft_strsplit(hms, ':');
	d->hour = ft_atoi(tmp[0]);
	d->min = ft_atoi(tmp[1]);
	d->sec = ft_atoi(tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
}

void		ft_date_time(long int t, t_date *d)
{
	char	*str;
	char	**tmp;

	str = ctime(&t);
	tmp = ft_strsplit(str, ' ');
	d->year = ft_atoi(tmp[4]);
	d->mon = ft_strdup(tmp[1]);
	d->mday = ft_atoi(tmp[2]);
	d->sday = ft_strdup(tmp[0]);
	get_hms(tmp[3], d);
	ft_free_tmp(tmp);
}
