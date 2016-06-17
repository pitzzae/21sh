/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_key_fn1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 22:46:19 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 17:05:22 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_move_left(t_dat *t_d)
{
	int		i;

	i = 1;
	if (t_d->pos_x > 0 &&
		((t_d->pos_x + ft_strlen(t_d->prompt)) % t_d->nb_col) != 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		t_d->pos_x--;
	}
	else if (t_d->pos_x > 0)
	{
		tputs(tgetstr("up", NULL), 1, ft_myputchar);
		while (i < t_d->nb_col)
		{
			tputs(tgetstr("nd", NULL), 1, ft_myputchar);
			i++;
		}
		t_d->pos_x--;
		t_d->pos_y--;
	}
}

void	ft_move_right(t_dat *t_d)
{
	int		i;

	i = 1;
	if (t_d->pos_x < t_d->max_x &&
		((t_d->pos_x + ft_strlen(t_d->prompt) + 1) % t_d->nb_col) != 0)
	{
		tputs(tgetstr("nd", NULL), 1, ft_myputchar);
		t_d->pos_x++;
	}
	else if (t_d->pos_x < t_d->max_x)
	{
		while (i < t_d->nb_col)
		{
			tputs(tgetstr("le", NULL), 1, ft_myputchar);
			i++;
		}
		tputs(tgetstr("do", NULL), 1, ft_myputchar);
		t_d->pos_x++;
		t_d->pos_y++;
	}
}

void	ft_move_end(t_dat *t_d)
{
	if (((t_d->pos_x + ft_strlen(t_d->prompt)) % t_d->nb_col) == 0)
		t_d->pos_x++;
	while (t_d->pos_x < t_d->max_x)
		ft_move_right(t_d);
	t_d->pos_x = t_d->max_x;
	t_d->pos_y = t_d->max_y;
}

void	ft_move_home(t_dat *t_d)
{
	if ((t_d->pos_x + ft_strlen(t_d->prompt) % t_d->nb_col) == 0)
	{
		t_d->pos_x--;
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
	}
	while (t_d->pos_x > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		t_d->pos_x--;
	}
	t_d->pos_x = 0;
	t_d->pos_y = 1;
}

void	ft_move_cursor(t_dat *t_d)
{
	if (t_d->buf[2] == 68)
		ft_move_left(t_d);
	else if (t_d->buf[2] == 67)
		ft_move_right(t_d);
	else if (t_d->buf[2] == 72)
		ft_move_home(t_d);
	else if (t_d->buf[2] == 70)
		ft_move_end(t_d);
	else if (t_d->buf[2] == 65)
		ft_history_top(t_d);
	else if (t_d->buf[2] == 66)
		ft_history_bot(t_d);
	else if (t_d->buf[2] == 91)
	{
		if (t_d->buf[3] == 67)
			ft_move_word_right(t_d);
		else if (t_d->buf[3] == 68)
			ft_move_word_left(t_d);
		else if (t_d->buf[3] == 65 && t_d->max_y > 1)
			ft_move_word_up(t_d);
		else if (t_d->buf[3] == 66 && t_d->max_y > 1)
			ft_move_word_down(t_d);
	}
}
