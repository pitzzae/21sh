/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 01:35:32 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:43:18 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_close_all_other(t_dat *t_d, int i)
{
	if (ft_strocur(t_d->cmd, '(') != 0 && t_d->cmd[i] == '(' &&
		t_d->cmd[i - 1] != '\\')
		i += ft_close_parent(t_d, i);
	else if (ft_strocur(t_d->cmd, '[') != 0 && t_d->cmd[i] == '[' &&
			t_d->cmd[i - 1] != '\\')
		i += ft_close_bracket(t_d, i);
	else if (ft_strocur(t_d->cmd, '{') != 0 && t_d->cmd[i] == '{' &&
			t_d->cmd[i - 1] != '\\')
		i += ft_close_cursh(t_d, i);
	return (i);
}

void			ft_complet_cmd(t_dat *t_d, int i)
{
	char		*start;
	char		*end;

	if (t_d->cmd[i])
		end = ft_strsub(t_d->cmd, i, ft_strlen(t_d->cmd) - (i));
	else
		end = ft_strdup("");
	start = ft_strsub_free(t_d->cmd, 0, i, 1);
	start = ft_strjoin_free(start, "\n", 1);
	ft_init_struct(t_d, t_d->prompt);
	if (get_action_key(t_d) == -1)
	{
		t_d->prompt = "";
		t_d->cmd = ft_strdup("\0");
		free(start);
		free(end);
		return ;
	}
	t_d->cmd = ft_strjoin_free(start, t_d->cmd, 3);
	t_d->cmd = ft_strjoin_free(t_d->cmd, end, 3);
	t_d->max_x = t_d->vmax_x;
	ft_move_end(t_d);
	tputs("\r\n", 1, ft_myputchar);
	if (ft_strcmp(t_d->prompt, "pipe>") == 0)
		ft_close_cmd(t_d, i + 1);
}

void			ft_close_cmd(t_dat *t_d, int i)
{
	while (t_d->cmd[i])
	{
		if (((ft_strocur(t_d->cmd, '"') != 0 && t_d->cmd[i] == '"') ||
			(ft_strocur(t_d->cmd, '`') != 0 && t_d->cmd[i] == '`') ||
			(ft_strocur(t_d->cmd, '\'') != 0 && t_d->cmd[i] == '\'')) &&
			t_d->cmd[i - 1] != '\\')
			i += ft_close_all_quote(t_d, i);
		else if (((ft_strocur(t_d->cmd, '(') != 0 && t_d->cmd[i] == '(') ||
			(ft_strocur(t_d->cmd, '[') != 0 && t_d->cmd[i] == '[') ||
			(ft_strocur(t_d->cmd, '{') != 0 && t_d->cmd[i] == '{')) &&
			t_d->cmd[i - 1] != '\\')
			i += ft_close_all_other(t_d, i);
		else if (t_d->cmd[i] == '<' && t_d->cmd[i + 1] == '<' &&
			t_d->cmd[i + 2] && t_d->cmd[i + 2] != ';')
			i += ft_close_read_input(t_d, i);
		i++;
	}
	if (ft_strlen(t_d->cmd) > 2 && t_d->cmd[ft_strlen(t_d->cmd) - 1] == '|')
		ft_close_pipe(t_d, i);
}
