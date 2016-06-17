/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfd_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 08:25:36 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:49:07 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void			ft_fd_push(t_mcmd *cmd, int in, int out)
{
	t_rfd		*nfd;
	int			i;

	if ((i = 0) && cmd->fd == NULL)
	{
		cmd->fd = (t_rfd*)malloc(sizeof(cmd->fd));
		cmd->fd[0].in = in;
		cmd->fd[0].out = out;
		cmd->fd_len = 1;
	}
	else
	{
		nfd = cmd->fd;
		cmd->fd = (t_rfd*)malloc(sizeof(cmd->fd) * cmd->fd_len + 1);
		while (i < cmd->fd_len)
		{
			cmd->fd[i].in = nfd[i].in;
			cmd->fd[i].out = nfd[i].out;
			i++;
		}
		cmd->fd[i].in = in;
		cmd->fd[i].out = out;
		cmd->fd_len++;
		free(nfd);
	}
}

static void			ft_merge_argv_list(char **argv, int j, int k)
{
	while (argv[j] && argv[j + 1] && argv[j + 2] && argv[j + k])
	{
		free(argv[j]);
		argv[j] = ft_strdup(argv[j + k]);
		j++;
	}
	while (argv[j])
	{
		if (j > 0)
		{
			free(argv[j]);
			argv[j] = NULL;
		}
		j++;
	}
}

static void			ft_multi_fd_redirect(t_mcmd **cmd, int in, int out)
{
	int		i;

	i = 1;
	while (i < 3)
	{
		if (out == -1)
			ft_fd_push(cmd[0], i, -1);
		else
			ft_fd_push(cmd[0], i, out);
		i++;
	}
}

int					ft_isfd_tofd(t_mcmd **cmd, char **argv, int i)
{
	int			j;
	int			k;
	int			in;
	int			out;

	in = ft_getfd_in(argv[i]);
	out = ft_getfd_out(argv[i], argv[i + 1]);
	j = i;
	k = 2;
	if (in >= -1 && out >= -1)
	{
		if (in < 0)
			ft_multi_fd_redirect(cmd, in, out);
		else
			ft_fd_push(cmd[0], in, out);
		if (ft_strcmp(ft_get_type_redirect(argv[i]), "<<") == 0)
			k++;
		ft_merge_argv_list(argv, j, k);
		return (1);
	}
	return (-1);
}

int					ft_isfd_redirect(char *op)
{
	int			i;

	i = ft_strlen(op) - 1;
	if (ft_strcmp(&op[i - 1], ">&") == 0 || ft_strcmp(&op[i - 1], "&>") == 0 ||
		ft_strcmp(&op[i - 1], ">>") == 0 || ft_strcmp(&op[i], ">") == 0 ||
		ft_strcmp(&op[0], "<<") == 0 || ft_strcmp(&op[i], "<") == 0)
		return (0);
	else
		return (1);
}
