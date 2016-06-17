/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 10:09:10 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/27 10:09:12 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_count_elements(t_lstenv **t_env)
{
	t_lstenv		*t_envtmp;
	int				i;

	i = 0;
	t_envtmp = t_env[0];
	while (t_envtmp != NULL)
	{
		t_envtmp = t_envtmp->next;
		i++;
	}
	return (i);
}

static void	ft_merge_env(t_lstenv **t_env, char ***ret, int merge)
{
	int				i;
	int				j;

	i = ft_count_elements(t_env) + merge;
	j = 0;
	while (j < i && ret[0] != NULL)
	{
		free(ret[0][j]);
		j++;
	}
	free(ret[0]);
}

void		ft_lst_to_env(t_lstenv **t_env, char ***ret, int merge)
{
	t_lstenv		*t_envtmp;
	int				i;

	i = ft_count_elements(t_env);
	if (merge > 0)
		ft_merge_env(t_env, ret, merge - 1);
	ret[0] = (char**)malloc(sizeof(ret[0]) * (i + 1));
	i = 0;
	t_envtmp = t_env[0];
	while (t_envtmp != NULL)
	{
		ret[0][i] = ft_strjoin(t_envtmp->opt, "=");
		if (t_envtmp->value)
			ret[0][i] = ft_strjoin_free(ret[0][i], t_envtmp->value, 1);
		t_envtmp = t_envtmp->next;
		i++;
	}
	ret[0][i] = NULL;
}
