/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 19:12:30 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/16 15:48:24 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void		ft_pipe_command(t_pid *e)
{
	if ((e->cmd->op && ft_strcmp(e->cmd->op, "|") == 0))
	{
		close(e->exe->c[e->i].out[0]);
		dup2(e->exe->c[e->i].out[1], 1);
		close(e->exe->c[e->i].out[0]);
	}
	if (e->cmd->prev && e->cmd->prev->op &&
		ft_strcmp(e->cmd->prev->op, "|") == 0)
	{
		close(e->exe->c[e->i - 1].out[1]);
		dup2(e->exe->c[e->i - 1].out[0], 0);
		close(e->exe->c[e->i - 1].out[1]);
	}
}
