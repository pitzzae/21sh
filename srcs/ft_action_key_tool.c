/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action_key_tool.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 18:07:34 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 17:03:15 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_dat	*ft_init_prompt(t_dat *t_d, int g)
{
	static t_dat *t_dtmp;

	if (g == 1)
	{
		t_dtmp = t_d;
	}
	return (t_dtmp);
}

void			get_sigint(int sig)
{
	t_dat *t_d;

	if (sig != 2)
	{
		t_d = ft_init_prompt(NULL, 0);
		t_d->max_x = t_d->vmax_x;
		ft_move_end(t_d);
		ft_putstr("\r\n");
		t_d->prompt = t_d->init_p;
		ft_putstr(t_d->prompt);
		free(t_d->cmd);
		t_d->cmd = ft_strnew(0);
		ft_bzero(t_d->cmd, 1);
		t_d->pos_x = 0;
		t_d->max_x = 0;
		t_d->vmax_x = 0;
		t_d->pos_y = 1;
		t_d->max_y = 1;
	}
}

void			ft_init_struct(t_dat *t_d, char *prompt)
{
	t_d->prompt = prompt;
	ft_init_prompt(t_d, 1);
	ft_putstr(t_d->prompt);
	t_d->cmd = ft_strnew(0);
	ft_bzero(t_d->cmd, 1);
	t_d->pos_x = 0;
	t_d->max_x = 0;
	t_d->vmax_x = 0;
	t_d->pos_y = 1;
	t_d->max_y = 1;
}

void			clear_buffer(t_dat *t_d)
{
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	t_d->nb_col = win.ws_col;
	t_d->nb_row = win.ws_row;
	t_d->buf[0] = 0;
	t_d->buf[1] = 0;
	t_d->buf[2] = 0;
	t_d->buf[3] = 0;
	t_d->buf[4] = 0;
	t_d->buf[5] = 0;
}

void			ft_show_cmd(t_dat *t_d, char *cmd)
{
	int i;

	i = ft_strlen(cmd) + ft_strlen(t_d->prompt);
	while (i > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		tputs("   ", 1, ft_myputchar);
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		tputs(tgetstr("le", NULL), 1, ft_myputchar);
		i--;
	}
	tputs(t_d->prompt, 1, ft_myputchar);
	tputs(t_d->cmd, 1, ft_myputchar);
	ft_replace_cursor(t_d);
}
