/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_key_fn2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 23:03:35 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 17:04:00 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_get_best_place(t_dat *t_d)
{
	int			i[2];

	i[0] = 0;
	i[1] = 0;
	while (t_d->pos_x + i[0] < t_d->max_x && t_d->pos_x + i[1] > 0)
	{
		i[0]++;
		i[1]++;
		if (t_d->cmd[t_d->pos_x + i[0]] == ' ')
			return (1);
		else if (t_d->cmd[t_d->pos_x + i[1]] == ' ')
			return (0);
	}
	return (0);
}

void		ft_move_word_down(t_dat *t_d)
{
	int			pos_x;

	pos_x = t_d->nb_col;
	if (((t_d->pos_x + ft_strlen(t_d->prompt)) % t_d->nb_col) == 0)
		t_d->pos_x++;
	while (pos_x > 0 && t_d->pos_x < t_d->max_x)
	{
		pos_x--;
		ft_move_right(t_d);
	}
	if (ft_get_best_place(t_d) == 0)
		ft_move_word_right(t_d);
	else
	{
		ft_move_word_left(t_d);
		ft_move_word_right(t_d);
	}
}

void		ft_move_word_up(t_dat *t_d)
{
	int			pos_x;

	pos_x = t_d->nb_col;
	if ((t_d->pos_x + ft_strlen(t_d->prompt) % t_d->nb_col) == 0)
	{
		t_d->pos_x--;
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
	}
	while (pos_x > 0 && t_d->pos_x > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		t_d->pos_x--;
		pos_x--;
	}
	if (ft_get_best_place(t_d) == 0)
		ft_move_word_right(t_d);
	else
	{
		ft_move_word_left(t_d);
		ft_move_word_right(t_d);
	}
}

void		ft_move_word_right(t_dat *t_d)
{
	int			f;

	f = 0;
	if (((t_d->pos_x + ft_strlen(t_d->prompt)) % t_d->nb_col) == 0)
		t_d->pos_x++;
	while (t_d->pos_x < t_d->max_x &&
		(t_d->cmd[t_d->pos_x - 1] != ' ' || f == 0))
	{
		f = 1;
		ft_move_right(t_d);
	}
}

void		ft_move_word_left(t_dat *t_d)
{
	int			pos_x;
	int			f;

	f = 0;
	pos_x = t_d->pos_x;
	if ((t_d->pos_x + ft_strlen(t_d->prompt) % t_d->nb_col) == 0)
	{
		t_d->pos_x--;
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
	}
	while (t_d->pos_x > 0 && (t_d->cmd[t_d->pos_x] != ' ' || f == 0))
	{
		f = 1;
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		t_d->pos_x--;
	}
}
