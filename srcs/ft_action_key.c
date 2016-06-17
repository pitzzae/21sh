/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 22:32:27 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 17:08:10 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		ft_remove_char_left(t_dat *t_d)
{
	char	*tmp;
	int		pos_x;

	if (t_d->pos_x == t_d->max_x)
	{
		t_d->cmd = ft_strsub_free(t_d->cmd, 0, ft_strlen(t_d->cmd) - 1, 1);
		t_d->replace = 1;
	}
	else
	{
		tmp = ft_strsub(t_d->cmd, 0, t_d->pos_x - 1);
		t_d->cmd = ft_strjoin_free(tmp, ft_strsub_free(t_d->cmd,
			t_d->pos_x, t_d->max_x - t_d->pos_x, 1), 3);
		pos_x = t_d->pos_x;
		while (pos_x < t_d->max_x)
		{
			tputs(" ", 1, ft_myputchar);
			pos_x++;
		}
		t_d->replace = 0;
	}
	t_d->pos_y = ((t_d->pos_x + ft_strlen(t_d->prompt)) / t_d->nb_col) + 1;
	t_d->pos_x--;
	t_d->max_x--;
}

static void		ft_remove_char_right(t_dat *t_d)
{
	char	*tmp;
	int		pos_x;

	tmp = ft_strsub_free(t_d->cmd, t_d->pos_x + 1,
		t_d->max_x - (t_d->pos_x + 1), 1);
	tputs(tmp, 1, ft_myputchar);
	tputs("   ", 1, ft_myputchar);
	tputs(tgetstr("le", NULL), 1, ft_myputchar);
	tputs(tgetstr("le", NULL), 1, ft_myputchar);
	if (t_d->max_x + ft_strlen(t_d->prompt) + 1 < t_d->nb_col)
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
	pos_x = t_d->pos_x;
	if (t_d->max_x + ft_strlen(t_d->prompt) + 1 == t_d->nb_col)
	{
		while (t_d->pos_x < pos_x)
			ft_move_right(t_d);
	}
	t_d->max_x--;
	t_d->pos_x = t_d->max_x;
	t_d->cmd = ft_strjoin_free(ft_strsub(t_d->cmd, 0, pos_x), tmp, 3);
	ft_move_home(t_d);
	ft_move_end(t_d);
	ft_move_home(t_d);
	while (t_d->pos_x < pos_x)
		ft_move_right(t_d);
}

void			ft_add_char(t_dat *t_d, char *buf)
{
	char	*tmp;
	int		i;

	i = 1;
	if (t_d->pos_x == t_d->max_x)
	{
		t_d->cmd = ft_strjoin_free(t_d->cmd, &buf[0], 1);
		t_d->replace = 1;
	}
	else
	{
		tmp = ft_strjoin_free(&buf[0], ft_strsub(t_d->cmd, t_d->pos_x,
			t_d->max_x - t_d->pos_x), 2);
		t_d->cmd = ft_strjoin_free(ft_strsub_free(t_d->cmd, 0, t_d->pos_x, 1),
			tmp, 3);
		t_d->replace = 0;
	}
	t_d->pos_y = ((t_d->pos_x + ft_strlen(t_d->prompt)) / t_d->nb_col) + 1;
	t_d->pos_x++;
	t_d->max_x++;
	if (t_d->vmax_x < t_d->max_x)
		t_d->vmax_x = t_d->max_x;
}

void			ft_replace_cursor(t_dat *t_d)
{
	int		i;

	i = ft_strlen(t_d->cmd) - t_d->pos_x;
	if (((t_d->max_x + ft_strlen(t_d->prompt)) % t_d->nb_col) == 0)
		i--;
	while (i > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		i--;
	}
	if (t_d->replace == 1)
	{
		ft_move_home(t_d);
		ft_move_end(t_d);
	}
}

int				get_action_key(t_dat *t_d)
{
	while (1)
	{
		clear_buffer(t_d);
		read(0, t_d->buf, 6);
		get_action_key_fn3(t_d);
		if (t_d->buf[0] == 27 && (t_d->buf[1] == 91 || t_d->buf[1] == 27) &&
			t_d->buf[2] != 51)
			ft_move_cursor(t_d);
		else if (t_d->buf[1] == 0 && t_d->buf[2] == 0 &&
			((t_d->buf[0] >= 32 && t_d->buf[0] <= 126)))
			ft_add_char(t_d, &t_d->buf[0]);
		else if (t_d->buf[0] == 127 && t_d->buf[1] == 0 &&
			t_d->buf[2] == 0 && ft_strlen(t_d->cmd) > 0 && t_d->pos_x > 0)
			ft_remove_char_left(t_d);
		else if (t_d->buf[0] == 27 && t_d->buf[1] == 91 && t_d->buf[2] == 51 &&
			ft_strlen(t_d->cmd) > 0 && t_d->pos_x < t_d->max_x)
			ft_remove_char_right(t_d);
		else if (t_d->buf[0] == 10 && t_d->buf[1] == 0 && t_d->buf[2] == 0)
			return (1);
		else if (t_d->buf[0] == 4 && write(1, "\n", 1))
			return (-1);
		if (t_d->buf[0] != 27 && t_d->buf[0] > 0)
			ft_show_cmd(t_d, t_d->cmd);
		t_d->max_y = ((t_d->max_x + ft_strlen(t_d->prompt)) / t_d->nb_col) + 1;
	}
}
