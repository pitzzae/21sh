/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:54:01 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 17:00:33 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		ft_cd(t_dat *t_d)
{
	struct passwd	*pw;
	char			cwd[1024];
	int				state;

	pw = getpwuid(getuid());
	if (ft_strcmp(t_d->argv[1], "-") == 0)
	{
		if (ft_lst_get_env(&t_d->t_env, "OLDPWD") != NULL)
			state = chdir(ft_lst_get_env(&t_d->t_env, "OLDPWD"));
		else
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
	}
	else
		state = ft_get_spath(&t_d->argv, pw->pw_dir, 1);
	ft_check_pwd(state, t_d->argv[1]);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		free(t_d->init_p);
		t_d->init_p = ft_strjoin(cwd, " $>");
		ft_update_env(t_d, cwd);
	}
}

void			ft_builtins_cd(t_dat *t_d)
{
	if (ft_len_argv(t_d->argv) == 2)
		ft_cd(t_d);
	if (ft_len_argv(t_d->argv) > 2)
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putstr_fd(t_d->argv[1], 2);
		ft_putstr_fd("\n", 2);
	}
}
