/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 12:04:03 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 16:59:56 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char			*ft_get_cwd(void)
{
	char			cwd[1024];
	char			*tmp;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		tmp = ft_strdup(cwd);
	else
		tmp = ft_strdup("/");
	return (tmp);
}

void				ft_check_env(t_dat *t_d, char ***env)
{
	t_lstenv		*t_envtmp;
	t_lstenv		*t_envtmp_next;
	char			**tmpenv;
	int				i;

	ft_lst_to_env(&t_d->t_env, &tmpenv, 0);
	ft_lst_env_new(tmpenv, &t_envtmp, 0);
	if (ft_lst_get_env(&t_envtmp, "PWD") == NULL)
		ft_lst_add_env(&t_envtmp, ft_strdup("PWD"), ft_get_cwd());
	if (ft_lst_get_env(&t_envtmp, "SHLVL") == NULL)
		ft_lst_add_env(&t_envtmp, ft_strdup("SHLVL"), ft_strdup("1"));
	ft_lst_to_env(&t_envtmp, env, 0);
	i = 0;
	while (tmpenv[i])
		free(tmpenv[i++]);
	free(tmpenv);
	while (t_envtmp)
	{
		t_envtmp_next = t_envtmp->next;
		free(t_envtmp->opt);
		free(t_envtmp->value);
		free(t_envtmp);
		t_envtmp = t_envtmp_next;
	}
}

void				ft_update_shlvl(t_lstenv **t_env)
{
	int				shlvl;
	char			*chlvl;

	chlvl = ft_lst_get_env(t_env, "SHLVL");
	if (chlvl == NULL)
		chlvl = ft_strdup("1");
	shlvl = ft_atoi(chlvl);
	shlvl++;
	free(chlvl);
	chlvl = ft_itoa(shlvl);
	ft_lst_edit_env(t_env, "SHLVL", chlvl, 0);
	free(chlvl);
	if (ft_lst_get_env(t_env, "_") == NULL)
		ft_lst_add_env(t_env, ft_strdup("_"), ft_strdup("/usr/bin/env"));
}

int					ft_len_argv(char **argv)
{
	int				i;

	i = 0;
	while (argv[i])
	{
		i++;
	}
	return (i);
}

void				ft_check_pwd(int state, char *argv)
{
	if (state == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(argv, 2);
		ft_putstr_fd("\n", 2);
	}
}
