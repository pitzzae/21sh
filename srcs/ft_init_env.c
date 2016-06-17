/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 22:28:29 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/05 18:23:59 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_send_ad_multiple(t_dat *t_d)
{
	char		**list_cmd;
	int			i[2];

	i[0] = 0;
	i[1] = 0;
	ft_close_cmd(t_d, 0);
	list_cmd = ft_strsplit(t_d->cmd, ';');
	while (list_cmd[i[0]] != 0)
	{
		if (ft_strocur(list_cmd[i[0]], ' ') != ft_strlen(list_cmd[i[0]]))
		{
			free(t_d->cmd);
			t_d->cmd = list_cmd[i[0]];
			ft_select_type(t_d);
			free(t_d->argv);
			i[1]++;
		}
		else
			free(list_cmd[i[0]]);
		i[0]++;
	}
	if (i[1] > 0)
		ft_add_history(t_d);
	free(list_cmd);
}

int				ft_initshell(t_dat *t_d, char *prompt)
{
	int			state;

	state = -1;
	ft_init_struct(t_d, prompt);
	if ((state = get_action_key(t_d)) == -1)
	{
		tputs("exit\n", 1, ft_myputchar);
		ft_reset_termios(t_d);
		return (-1);
	}
	else if (state == 1)
	{
		if (ft_strlen(t_d->cmd) > 0)
		{
			t_d->max_x = t_d->vmax_x;
			ft_move_end(t_d);
			tputs("\r\n", 1, ft_myputchar);
			ft_send_ad_multiple(t_d);
		}
		else
			tputs("\r\n", 1, ft_myputchar);
	}
	free(t_d->cmd);
	return (1);
}

int				ft_get_spath(char ***argv, char *homedir, int j)
{
	int			state;
	int			i;
	char		*tmp;

	i = 1;
	while (argv[0][i])
	{
		tmp = ft_str_replace_str(argv[0][i], "~", homedir);
		if (j == 0)
		{
			free(argv[0][i]);
			argv[0][i] = tmp;
		}
		i++;
	}
	if (j == 1)
	{
		state = chdir(tmp);
		free(tmp);
	}
	return (state);
}

void			ft_print_char_env(char **env, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		ft_putendl(env[i]);
		i++;
	}
}

int				ft_init_env(char ***env, char **envi)
{
	char cwd[1024];

	if (envi[0] == NULL)
	{
		env[0] = (char**)malloc(sizeof(env) * 4);
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			env[0][0] = ft_strjoin_free("PWD=", ft_strdup(cwd), 2);
		else
			env[0][1] = ft_strdup("PWD=/");
		env[0][1] = ft_strdup("SHLVL=1");
		env[0][2] = ft_strdup("_=/usr/bin/env");
		env[0][3] = NULL;
		return (1);
	}
	return (0);
}
