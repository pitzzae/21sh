/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_fd_redirect.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 21:34:44 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:44:03 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char			*ft_get_type_redirect(char *op)
{
	char		*ret;
	int			i;

	i = ft_strlen(op) - 1;
	ret = "";
	if (ft_strcmp(&op[i - 1], ">&") == 0)
		ret = ">&";
	else if (ft_strcmp(&op[i - 1], "&>") == 0)
		ret = "&>";
	else if (ft_strcmp(&op[i - 1], ">>") == 0)
		ret = ">>";
	else if (ft_strcmp(&op[i], ">") == 0)
		ret = ">";
	else if (ft_strcmp(&op[i - 1], "<<") == 0)
		ret = "<<";
	else if (ft_strcmp(&op[i], "<") == 0)
		ret = "<";
	return (ret);
}

void			ft_apply_fd_redirect(t_pid *e)
{
	int		i;

	i = 0;
	while (i < e->cmd->fd_len)
	{
		if (e->cmd->fd[i].in >= 0)
		{
			if (e->cmd->fd[i].out == -1)
				close(e->cmd->fd[i].in);
			else
				dup2(e->cmd->fd[i].out, e->cmd->fd[i].in);
		}
		i++;
	}
}
