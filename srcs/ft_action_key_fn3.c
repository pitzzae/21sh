/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_key_fn3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 00:20:48 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/06 00:20:50 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void		ft_copy_to_buf(t_dat *t_d)
{
	if (t_d->copy)
		free(t_d->copy);
	t_d->copy = ft_strsub(t_d->cmd, t_d->pos_x, t_d->max_x - t_d->pos_x);
	t_d->copy[t_d->max_x - t_d->pos_x] = '\0';
}

static void		ft_past_from_buf(t_dat *t_d)
{
	size_t			i;

	if (t_d->copy)
	{
		i = ft_strlen(t_d->copy);
		ft_add_char(t_d, &t_d->copy[0]);
		t_d->pos_x += i - 1;
		t_d->max_x += i - 1;
		if (t_d->max_x > t_d->vmax_x)
			t_d->vmax_x = t_d->max_x;
		ft_show_cmd(t_d, t_d->cmd);
	}
}

void			get_action_key_fn3(t_dat *t_d)
{
	if (t_d->buf[0] == -61 && t_d->buf[1] == -89)
		ft_copy_to_buf(t_d);
	else if (t_d->buf[0] == -30 && t_d->buf[1] == -120 && t_d->buf[2] == -102)
		ft_past_from_buf(t_d);
	else if (t_d->buf[0] == 10 && t_d->buf[1] == 0 && t_d->buf[2] == 0)
	{
		if (ft_strcmp(t_d->prompt, "pipe>") == 0)
			t_d->prompt = t_d->init_p;
	}
}
