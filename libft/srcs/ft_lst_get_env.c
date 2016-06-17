/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 10:40:21 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/27 10:40:23 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_lst_get_env(t_lstenv **t_env, char *opt)
{
	t_lstenv			*t_envtmp;

	t_envtmp = t_env[0];
	while (t_envtmp)
	{
		if (ft_strcmp(t_envtmp->opt, opt) == 0)
			return (t_envtmp->value);
		t_envtmp = t_envtmp->next;
	}
	return (NULL);
}
