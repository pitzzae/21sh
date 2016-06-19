/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 21:49:12 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 16:49:06 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		ft_reset_curso_hist(t_dat *t_d, t_list *tmp)
{
	char		*old_cmd;
	int			i;

	i = ft_strlen(t_d->cmd);
	old_cmd = t_d->cmd;
	t_d->cmd = ft_strdup(tmp->content);
	t_d->pos_x = 0;
	t_d->max_x = ft_strlen(t_d->cmd);
	if (t_d->max_x > t_d->vmax_x)
		t_d->vmax_x = t_d->max_x;
	t_d->pos_y = 1;
	t_d->max_y = ((t_d->max_x + ft_strlen(t_d->prompt)) / t_d->nb_col) + 1;
	while (i >= 0)
	{
		tputs(" ", 1, ft_myputchar);
		i--;
	}
	ft_show_cmd(t_d, old_cmd);
	ft_move_end(t_d);
	free(old_cmd);
}

void			ft_init_history(t_dat *t_d)
{
	char		cwd[1024];

	t_d->copy = NULL;
	t_d->hist = ft_lstnew("\0", 1);
	t_d->h_len = 0;
	t_d->h_pos = 0;
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		t_d->init_p = ft_strjoin(cwd, " $>");
	else
		t_d->init_p = ft_strdup("$>");
}

void			ft_add_history(t_dat *t_d, char *cmd, int i)
{
	t_list		*lst;
	char		*cmd_c;

	if (i > 0)
	{
		
		cmd_c = ft_str_replace_str(cmd, "\n", "");
		lst = ft_lstnew(cmd_c, ft_strlen(cmd_c) + 1);
		lst->select = t_d->vmax_x;
		ft_lstaddend_free(&t_d->hist, lst, u_del);
		t_d->h_len = ft_lstlen(t_d->hist);
		t_d->h_pos = t_d->h_len;
		free(cmd_c);
	}
	free(cmd);
}

void			ft_history_top(t_dat *t_d)
{
	t_list		*tmp;
	int			vpos;

	tmp = t_d->hist;
	vpos = 0;
	if (t_d->h_pos > 1)
	{
		t_d->h_pos--;
		while (vpos < t_d->h_pos && tmp != NULL)
		{
			tmp = tmp->next;
			vpos++;
		}
		ft_move_home(t_d);
		ft_reset_curso_hist(t_d, tmp);
	}
}

void			ft_history_bot(t_dat *t_d)
{
	t_list		*tmp;
	char		*old_cmd;
	int			vpos;

	tmp = t_d->hist;
	vpos = 0;
	if (t_d->h_pos < t_d->h_len - 1)
	{
		t_d->h_pos++;
		while (vpos < t_d->h_pos && tmp != NULL)
		{
			tmp = tmp->next;
			vpos++;
		}
		ft_move_home(t_d);
		ft_reset_curso_hist(t_d, tmp);
	}
	else if (t_d->h_pos < t_d->h_len)
	{
		t_d->h_pos++;
		ft_move_home(t_d);
		ft_reset_curso_hist(t_d, tmp);
	}
}
