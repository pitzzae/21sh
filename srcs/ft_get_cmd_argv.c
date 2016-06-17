/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 08:05:38 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 16:57:40 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		ft_replace_argv(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
	str[i] = '\0';
}

static int		ft_apply_argv(char *cmd, int pos)
{
	if (cmd[pos] == ' ')
		cmd[pos] = 1;
	if (cmd[pos] == '\'' && cmd[pos - 1] != '\\')
	{
		ft_replace_argv(&cmd[pos]);
		while (cmd[pos] && cmd[pos] != '\'' && cmd[pos - 1] != '\\')
			pos++;
		cmd[pos] = ' ';
	}
	if (cmd[pos] == '"' && cmd[pos - 1] != '\\')
	{
		ft_replace_argv(&cmd[pos]);
		while (cmd[pos] && cmd[pos] != '"' && cmd[pos - 1] != '\\')
			pos++;
		cmd[pos] = ' ';
	}
	if (cmd[pos] == '`' && cmd[pos - 1] != '\\')
	{
		ft_replace_argv(&cmd[pos]);
		while (cmd[pos] && cmd[pos] != '`' && cmd[pos - 1] != '\\')
			pos++;
		cmd[pos] = ' ';
	}
	return (pos);
}

void			ft_get_cmd_argv(t_dat *t_d)
{
	char		**argv;
	char		*cmd;
	int			argc;
	int			pos;

	pos = 0;
	argc = 0;
	cmd = ft_strjoin_free(ft_strdup(t_d->cmd), " ", 1);
	ft_add_space(&cmd);
	while (cmd[pos])
	{
		if (argc == 0 && cmd[pos] == ' ')
		{
			cmd[pos] = 1;
			argc++;
		}
		else
			pos = ft_apply_argv(cmd, pos);
		pos++;
	}
	t_d->argv = ft_strsplit_len(cmd, 1, &t_d->argc);
	free(cmd);
	free(t_d->cmd);
	t_d->cmd = t_d->argv[0];
}
