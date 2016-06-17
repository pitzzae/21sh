/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_cmd_fn1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 04:08:59 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/06 04:25:15 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_openclose(char *cmd, char o, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] == o)
			j++;
		else if (cmd[i] == c)
			j--;
		i++;
	}
	return (j);
}

int				ft_close_cursh(t_dat *t_d, int i)
{
	int		pos;
	int		len;

	len = 0;
	t_d->prompt = "cursh>";
	pos = ft_openclose(t_d->cmd, '{', '}');
	while (pos != 0 && ft_strcmp(t_d->prompt, "cursh>") == 0)
	{
		ft_complet_cmd(t_d, i);
		pos = ft_openclose(t_d->cmd, '{', '}');
		len++;
	}
	return (len);
}

int				ft_close_parent(t_dat *t_d, int i)
{
	int		pos;
	int		len;

	len = 0;
	t_d->prompt = "parent>";
	pos = ft_openclose(t_d->cmd, '(', ')');
	while (pos != 0 && ft_strcmp(t_d->prompt, "parent>") == 0)
	{
		ft_complet_cmd(t_d, i);
		pos = ft_openclose(t_d->cmd, '(', ')');
		len++;
	}
	return (len);
}

int				ft_close_bracket(t_dat *t_d, int i)
{
	int		pos;
	int		len;

	len = 0;
	t_d->prompt = "bracket>";
	pos = ft_openclose(t_d->cmd, '[', ']');
	while (pos != 0 && ft_strcmp(t_d->prompt, "bracket>") == 0)
	{
		ft_complet_cmd(t_d, i);
		pos = ft_openclose(t_d->cmd, '[', ']');
		len++;
	}
	return (len);
}

void			ft_close_pipe(t_dat *t_d, int i)
{
	t_d->prompt = "pipe>";
	while (ft_strcmp(t_d->prompt, "pipe>") == 0)
	{
		ft_complet_cmd(t_d, i);
	}
}
