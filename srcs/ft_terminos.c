/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 13:34:04 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:43:44 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int			ft_exit_minishell(t_dat *t_d, int e)
{
	ft_reset_termios(t_d);
	exit(e);
}

int			ft_init_termios(t_dat *t_d, int i)
{
	struct winsize		win;

	if (tgetent(NULL, getenv("TERM")) < 1)
	{
		ft_putstr_fd("error: env TERM not set\n", 2);
		return (0);
	}
	if (tcgetattr(0, &(t_d->term)) == -1)
		return (0);
	if (i == 1 && tcgetattr(0, &(t_d->bterm)) == -1)
		return (0);
	t_d->term.c_lflag &= ~(ICANON | ECHO);
	t_d->term.c_cc[VMIN] = 1;
	t_d->term.c_cc[VTIME] = 0;
	ioctl(0, TIOCGWINSZ, &win);
	t_d->nb_col = win.ws_col;
	t_d->nb_row = win.ws_row;
	if (tcsetattr(0, 0, &(t_d->term)) == -1)
		return (0);
	return (1);
}

int			ft_reset_termios(t_dat *t_d)
{
	if (tcsetattr(0, 0, &(t_d->bterm)) == -1)
		return (0);
	return (1);
}
