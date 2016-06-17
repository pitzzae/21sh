/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins_history.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 05:00:34 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 16:58:10 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_builtins_history(t_dat *t_d)
{
	t_list		*hist;

	hist = t_d->hist;
	hist = hist->next;
	ft_lstprintstr(hist);
}
