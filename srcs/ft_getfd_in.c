/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfd_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:42:53 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:41:03 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_getint(char *op, char *sop)
{
	char		*nop;
	int			i;

	nop = ft_str_replace_str(op, sop, "");
	if (ft_strlen(nop) == 0 && (ft_strcmp(sop, ">") == 0 ||
		ft_strcmp(sop, ">>") == 0 || ft_strcmp(sop, ">&") == 0 ||
		ft_strcmp(sop, "&<") == 0))
		i = 1;
	else if (ft_strlen(nop) == 0 && (ft_strcmp(sop, "<") == 0 ||
		ft_strcmp(sop, "<<") == 0))
		i = 0;
	else
	{
		i = ft_atoi(nop);
		if (i < 0)
			i = -i;
		if ((i == 0 && ft_strcmp(nop, "0") != 0))
			i = -2;
	}
	free(nop);
	return (i);
}

int				ft_getfd_in(char *op)
{
	char		*nop;
	int			i;

	nop = ft_get_type_redirect(op);
	i = ft_strlen(op) - ft_strlen(nop);
	if (ft_strcmp(nop, "") != 0 && ft_strcmp(nop, "&>") != 0 &&
		ft_strcmp(&op[i], nop) == 0)
		return (ft_getint(op, nop));
	else if ((ft_strcmp(nop, "") != 0 || ft_strcmp(nop, "&>") == 0) &&
		ft_strcmp(&op[i], nop) == 0)
		return (-1);
	else
		return (-2);
}
