/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 09:47:14 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/16 15:50:00 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void			ft_start_new_pid(t_pid *e)
{
	if (ft_is_builtins(e->t_d) == 1)
	{
		if (!(e->cmd->prev && e->cmd->prev->op &&
			ft_strcmp(e->cmd->prev->op, "||") == 0 && e->st == 0))
		{
			ft_pipe_command(e);
			ft_apply_fd_redirect(e);
			if (execve(e->cmd->cmd, e->cmd->argv, e->t_d->env) == -1)
			{
				ft_puterror(e->t_d->cmd, 1);
			}
		}
		else
			exit(0);
	}
}

static void			ft_waiting_end_pid(t_pid *e)
{
	e->st = wait_child();
	close(e->exe->c[e->i].out[1]);
	if (e->cmd->op && ft_strcmp(e->cmd->op, "&&") == 0 && e->st != 0)
	{
		while (e->cmd->next)
			e->cmd = e->cmd->next;
	}
	if (e->cmd->next && (e->cmd = e->cmd->next))
		ft_next_pid(e);
	else
	{
		while (read(e->exe->c[e->i].out[0], &e->exe->ch, 1) == 1)
			write(1, &e->exe->ch, 1);
		ft_init_termios(e->t_d, 0);
		ft_free_t_mcmd(e->cmd, e->exe);
		ft_free_newenv(e->exe->new_env);
	}
}

void				ft_next_pid(t_pid *e)
{
	e->i = e->cmd->pos;
	if ((e->exe->pid = fork()) == 0)
		ft_start_new_pid(e);
	else if (e->exe->pid != -1)
		ft_waiting_end_pid(e);
}

void				ft_init_new_cmd(t_dat *t_d, t_execmd *exe, t_mcmd *cmd)
{
	t_pid		e;

	ft_reset_termios(t_d);
	ft_init_pipe(exe, cmd);
	exe->pw = getpwuid(getuid());
	ft_check_env(t_d, &exe->new_env);
	ft_update_cmd_path(t_d, cmd);
	e.exe = exe;
	e.t_d = t_d;
	e.cmd = cmd;
	e.st = 0;
	if (cmd->error == 1)
	{
		ft_putstr_fd("minishell: parse error\n", 2);
		ft_init_termios(e.t_d, 0);
		ft_free_t_mcmd(e.cmd, e.exe);
		ft_free_newenv(e.exe->new_env);
	}
	else
		ft_next_pid(&e);
}
