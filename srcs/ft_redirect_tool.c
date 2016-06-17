/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_tool.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 06:25:24 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:46:51 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_update_cmd_path(t_dat *st_d, t_mcmd *scmd)
{
	t_mcmd		*cmd;
	t_dat		t_d;
	int			i;

	cmd = scmd;
	while (cmd)
	{
		t_d.cmd = cmd->cmd;
		t_d.t_env = st_d->t_env;
		t_d.argv = cmd->argv;
		if (ft_is_builtins(&t_d) == 1)
		{
			i = ft_get_list_cmd(&t_d);
			cmd->cmd = t_d.cmd;
		}
		cmd = cmd->next;
	}
}

void		ft_free_newenv(char **new_env)
{
	int				i;

	i = 0;
	while (new_env[i] && new_env[i][0])
	{
		free(new_env[i]);
		i++;
	}
	free(new_env);
}

void		ft_init_pipe(t_execmd *c, t_mcmd *cmd)
{
	t_mcmd			*ncmd;
	int				i;
	int				j;

	i = 0;
	j = 2;
	ncmd = cmd;
	while (ncmd->next && (j++))
		ncmd = ncmd->next;
	c->c = (t_pipe*)malloc(sizeof(t_pipe) * (j + 1));
	while (i < j)
	{
		if (pipe(c->c[i].in) < 0 || pipe(c->c[i].out) < 0)
		{
			ft_putstr_fd("Can't make pipe\n", 2);
			exit(1);
		}
		i++;
	}
	if (pipe(c->p.in) < 0 || pipe(c->p.out) < 0)
	{
		ft_putstr_fd("Can't make pipe\n", 2);
		exit(1);
	}
}

void		ft_free_t_mcmd(t_mcmd *fcmd, t_execmd *exe)
{
	t_mcmd			*tmp_cmd;
	t_mcmd			*cmd;
	int				i;

	free(exe->c);
	cmd = fcmd;
	while (cmd->prev)
		cmd = cmd->prev;
	while (cmd)
	{
		free(cmd->fd);
		if (cmd->op)
			free(cmd->op);
		if (cmd->cmd)
			free(cmd->cmd);
		i = 0;
		while (cmd->argv[i] != 0)
			free(cmd->argv[i++]);
		free(cmd->argv);
		tmp_cmd = cmd->next;
		free(cmd);
		cmd = tmp_cmd;
	}
}

void		ft_init_new_t_mcmd(t_mcmd **mcmd, char *cmd, t_mcmd *prev, int i)
{
	mcmd[0] = (t_mcmd*)malloc(sizeof(t_mcmd));
	mcmd[0]->cmd = ft_strdup(cmd);
	mcmd[0]->fd = NULL;
	mcmd[0]->pos = i;
	mcmd[0]->fd_len = 0;
	mcmd[0]->op = NULL;
	mcmd[0]->argv = (char**)malloc(sizeof(char**));
	mcmd[0]->argv[0] = 0;
	mcmd[0]->argc = 0;
	mcmd[0]->next = NULL;
	mcmd[0]->error = 0;
	mcmd[0]->prev = prev;
}
