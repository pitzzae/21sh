/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_redirect_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 02:04:39 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/10 02:04:41 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int			ft_fdredirect_cmd(t_mcmd **cmd, char **argv, int i)
{
	int			ret;

	if ((ret = ft_isfd_tofd(cmd, argv, i)) == 1)
		return (ret);
	else
		return (ret);
}

static void			ft_add_op(t_mcmd **cmd, char **out, int i)
{
	char		*new_cmd;

	cmd[0]->op = ft_strdup(out[i]);
	if (out[i + 1])
		new_cmd = out[i + 1];
	else
		new_cmd = "";
	ft_init_new_t_mcmd(&cmd[0]->next, new_cmd, cmd[0], cmd[0]->pos + 1);
	cmd[0] = cmd[0]->next;
}

static int			ft_is_operator(char *op)
{
	if (ft_strcmp(op, ";") == 0 ||
		ft_strcmp(op, "|") == 0 ||
		ft_strcmp(op, "||") == 0 ||
		ft_strcmp(op, "&") == 0 ||
		ft_strcmp(op, "&&") == 0)
		return (1);
	else
		return (0);
}

int					ft_read_redirect_cmd(t_mcmd **ncmd, char **out)
{
	int				i[2];

	i[0] = 0;
	while (out[i[0]])
	{
		i[1] = 0;
		if (ft_is_operator(out[i[0]]) == 1 && (i[1] = 1))
			ft_add_op(ncmd, out, i[0]);
		if (ft_isfd_redirect(out[i[0]]) == 0 && out[i[0] + 1])
			i[0] -= ft_fdredirect_cmd(ncmd, out, i[0]);
		else
		{
			if (ft_isfd_redirect(out[i[0]]) == 0)
				ncmd[0]->error = 1;
			else if (i[1] == 0 &&
				((out[i[0] + 1] && ft_isfd_redirect(out[i[0] + 1]) != 0) ||
				!out[i[0] + 1]))
				ft_add_argv_cmd(ncmd, out, i[0]);
			i[0]++;
		}
	}
	return (1);
}
