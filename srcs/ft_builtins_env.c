/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 15:40:10 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/27 15:40:12 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		ft_print_env(t_dat *t_d, t_lstenv **t_env)
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
	ft_print_char_env(t_d->env, i);
}

static void		ft_setenv(t_dat *t_d, int set)
{
	if (set == 0)
	{
		if (ft_lst_get_env(&t_d->t_env, t_d->argv[1]) == NULL)
			ft_lst_add_env(&t_d->t_env, ft_strdup(t_d->argv[1]),
			ft_strdup(t_d->argv[2]));
		else
			ft_lst_edit_env(&t_d->t_env, t_d->argv[1], t_d->argv[2], 0);
	}
	else
	{
		if (ft_strcmp(t_d->argv[1], "_") != 0)
			ft_lst_rm_env(&t_d->t_env, t_d->argv[1]);
	}
	ft_lst_to_env(&t_d->t_env, &t_d->env, 1 + set);
	ft_print_env(t_d, &t_d->t_env);
}

void			ft_update_env(t_dat *t_d, char cwd[1024])
{
	char			*tmp;
	char			*tmp2;

	tmp2 = NULL;
	if ((tmp2 = ft_lst_get_env(&t_d->t_env, "OLDPWD")) != NULL)
		;
	if (ft_lst_get_env(&t_d->t_env, "PWD") != NULL &&
		ft_lst_edit_env(&t_d->t_env, "OLDPWD",
		ft_lst_get_env(&t_d->t_env, "PWD"), 0) == NULL)
		ft_lst_add_env(&t_d->t_env, ft_strdup("OLDPWD"),
		ft_lst_get_env(&t_d->t_env, "PWD"));
	else
	{
		if (tmp2 != NULL && ft_strcmp(tmp2, "") != 0)
			free(tmp2);
	}
	if (ft_lst_get_env(&t_d->t_env, "PWD") != NULL)
		ft_lst_edit_env(&t_d->t_env, "PWD", cwd, 1);
	ft_lst_to_env(&t_d->t_env, &t_d->env, 1);
}

int				ft_is_builtins(t_dat *t_d)
{
	if (ft_strcmp(t_d->cmd, "unsetenv") == 0 ||
		ft_strcmp(t_d->cmd, "setenv") == 0 || ft_strcmp(t_d->cmd, "cd") == 0 ||
		ft_strcmp(t_d->cmd, "env") == 0 || ft_strcmp(t_d->cmd, "history") == 0)
	{
		if (ft_strcmp(t_d->cmd, "env") == 0 && ft_len_argv(t_d->argv) == 1)
			ft_print_env(t_d, &t_d->t_env);
		if (ft_strcmp(t_d->cmd, "setenv") == 0 && ft_len_argv(t_d->argv) == 3)
			ft_setenv(t_d, 0);
		if (ft_strcmp(t_d->cmd, "unsetenv") == 0 && ft_len_argv(t_d->argv) == 2)
			ft_setenv(t_d, 1);
		if (ft_strcmp(t_d->cmd, "cd") == 0 && ft_len_argv(t_d->argv) == 2)
			ft_builtins_cd(t_d);
		if (ft_strcmp(t_d->cmd, "history") == 0 && ft_len_argv(t_d->argv) == 1)
			ft_builtins_history(t_d);
		return (0);
	}
	return (1);
}
