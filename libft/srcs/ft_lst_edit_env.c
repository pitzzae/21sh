/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_edit_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 11:00:02 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/27 11:00:04 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_lst_edit_env(t_lstenv **t_env, char *opt, char *value, int f)
{
	t_lstenv			*t_envtmp;

	t_envtmp = t_env[0];
	while (t_envtmp)
	{
		if (ft_strcmp(t_envtmp->opt, opt) == 0)
		{
			if (f == 1)
				free(t_envtmp->value);
			t_envtmp->value = ft_strdup(value);
			return (t_envtmp->value);
		}
		t_envtmp = t_envtmp->next;
	}
	return (NULL);
}
