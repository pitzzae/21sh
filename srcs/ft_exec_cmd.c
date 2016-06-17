/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 10:40:08 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/16 15:49:40 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int				ft_command_iserror(t_mcmd *cnmd)
{
	t_mcmd		*cmd;
	int			error;

	error = 0;
	cmd = cnmd;
	while (cmd)
	{
		if (cmd->error == 1)
			error = 1;
		if (!cmd->cmd || (cmd->op && (ft_strcmp(cmd->op, "&") == 0)) ||
			(ft_strcmp(cmd->cmd, "|") == 0 ||
			ft_strcmp(cmd->cmd, "||") == 0 || ft_strcmp(cmd->cmd, ">&") == 0 ||
			ft_strcmp(cmd->cmd, "&>") == 0 || ft_strcmp(cmd->cmd, ">>") == 0 ||
			ft_strcmp(cmd->cmd, ">") == 0 || ft_strcmp(cmd->cmd, "<") == 0))
			error = 1;
		cmd = cmd->next;
	}
	cmd = cnmd;
	while (cmd)
	{
		cmd->error = error;
		cmd = cmd->next;
	}
	return (0);
}

static char				**ft_add_cat_toread(char **argv)
{
	char		**out;
	int			len;

	len = 0;
	while (argv[len] != 0)
		len++;
	out = (char**)malloc(sizeof(out) * (len + 2));
	if (!out)
		return (NULL);
	out[0] = ft_strdup("cat");
	len = 1;
	while (argv[len - 1])
	{
		out[len] = ft_strdup(argv[len - 1]);
		free(argv[len - 1]);
		len++;
	}
	out[len] = NULL;
	free(argv);
	return (out);
}

static void				ft_redirect_cmd(t_dat *t_d)
{
	t_execmd	exe;
	t_mcmd		*cmd;
	char		**out;
	int			i;

	out = ft_tabdup(&t_d->argv[0]);
	free(out[0]);
	out[0] = ft_strdup(t_d->cmd);
	if (ft_strocur(out[0], '<') != 0 || ft_strocur(out[0], '>') != 0)
		out = ft_add_cat_toread(&out[0]);
	ft_init_new_t_mcmd(&cmd, out[0], NULL, 1);
	ft_read_redirect_cmd(&cmd, out);
	while (cmd->prev)
		cmd = cmd->prev;
	i = 0;
	ft_command_iserror(cmd);
	while (out[i])
		free(out[i++]);
	free(out);
	ft_init_new_cmd(t_d, &exe, cmd);
}

int						wait_child(void)
{
	int		status;

	wait(&status);
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 11)
			ft_putstr_fd("Segfault !\n", 2);
		else if (WTERMSIG(status) == 8)
			ft_putstr_fd("Arithmetic error !\n", 2);
		else
			ft_putstr_fd("Killed\n", 2);
	}
	else if (WIFSTOPPED(status))
		ft_putstr_fd("Stopped\n", 2);
	return (status);
}

void					ft_select_type(t_dat *t_d)
{
	int				builtins;

	ft_get_cmd_argv(t_d);
	if (ft_strcmp(t_d->cmd, "exit") == 0)
	{
		if (ft_len_argv(t_d->argv) == 2)
			ft_exit_minishell(t_d, ft_atoi(t_d->argv[1]));
		else if (ft_len_argv(t_d->argv) == 1)
			ft_exit_minishell(t_d, 0);
		else
			ft_putstr_fd("exit: too many arguments\n", 2);
		return ;
	}
	builtins = ft_is_builtins(t_d);
	if (t_d->cmd != NULL && builtins == 1)
		ft_redirect_cmd(t_d);
	else if (ft_strlen(t_d->cmd) > 0 && builtins == 1)
		ft_puterror(t_d->cmd, 0);
	builtins = 1;
	while (builtins < t_d->argc)
		free(t_d->argv[builtins++]);
}
