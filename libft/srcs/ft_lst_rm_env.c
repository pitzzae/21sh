/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rm_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:16:33 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/27 15:16:45 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_free_var(t_lstenv *t_envtmp)
{
	free(t_envtmp->opt);
	free(t_envtmp->value);
	free(t_envtmp);
}

char		*ft_lst_rm_env(t_lstenv **t_env, char *opt)
{
	t_lstenv			*t_envtmp;
	t_lstenv			*t_envnext;

	if (ft_strcmp(t_env[0]->opt, opt) == 0)
	{
		t_envnext = t_env[0]->next;
		ft_free_var(t_env[0]);
		t_env[0] = t_envnext;
		return (opt);
	}
	t_envtmp = (*t_env);
	while (t_envtmp->next)
	{
		if (ft_strcmp(t_envtmp->next->opt, opt) == 0)
		{
			t_envnext = t_envtmp->next->next;
			ft_free_var(t_envtmp->next);
			t_envtmp->next = t_envnext;
			return (opt);
		}
		t_envtmp = t_envtmp->next;
	}
	return (NULL);
}
