/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 11:25:25 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/25 11:25:27 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int			ft_path_bin(t_dat *t_d, struct dirent *dp, char *path)
{
	char			*tmp;

	tmp = ft_strjoin(path, "/");
	tmp = ft_strjoin_free(tmp, dp->d_name, 1);
	if (ft_strcmp(tmp, t_d->cmd) == 0)
	{
		free(tmp);
		return (1);
	}
	if (ft_strcmp(dp->d_name, t_d->cmd) == 0)
	{
		free(t_d->cmd);
		t_d->cmd = tmp;
		return (1);
	}
	free(tmp);
	return (0);
}

static int			ft_is_binary(t_dat *t_d)
{
	char			*path;
	struct passwd	*pw;

	pw = getpwuid(getuid());
	path = ft_lst_get_env(&t_d->t_env, "PWD");
	if (path == NULL)
		path = pw->pw_dir;
	if (t_d->cmd[0] == '.' && t_d->cmd[1] == '/')
		return (1);
	else if (t_d->cmd[0] == '/')
		return (1);
	return (0);
}

static int			ft_send_cmd(int out, t_dat *t_d)
{
	if (out == 1)
		return (1);
	return (ft_is_binary(t_d));
}

int					ft_get_list_cmd(t_dat *t_d)
{
	t_cmd			cmd;
	int				out;

	cmd.cbin = ft_lst_get_env(&t_d->t_env, "PATH");
	if (cmd.cbin == NULL)
		cmd.cbin = "/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin";
	cmd.bin = ft_strsplit(cmd.cbin, ':');
	cmd.i = 0;
	out = 0;
	while (cmd.bin[cmd.i])
	{
		if ((cmd.dir = opendir(cmd.bin[cmd.i])) != NULL)
		{
			while ((cmd.dp = readdir(cmd.dir)) != NULL)
			{
				if (ft_path_bin(t_d, cmd.dp, cmd.bin[cmd.i]) == 1)
					out = 1;
			}
			closedir(cmd.dir);
		}
		free(cmd.bin[cmd.i]);
		cmd.i++;
	}
	free(cmd.bin);
	return (ft_send_cmd(out, t_d));
}
