/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfd_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 19:49:44 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:45:36 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char		*ft_get_str_input(char *str)
{
	int		start;
	int		stop;
	char	*txt;

	start = ft_strfocur(str, '\n') + 1;
	stop = ft_strlocur(str, '\n');
	txt = ft_strsub(str, start, stop - start + 1);
	return (txt);
}

static int		ft_str_to_fd(char *str)
{
	int		i;
	int		p[2];
	char	*buf;

	i = 0;
	if (pipe(p) < 0)
	{
		ft_putstr_fd("Can't make pipe\n", 2);
		exit(1);
	}
	buf = ft_get_str_input(str);
	while (buf[i])
		write(p[1], &buf[i++], 1);
	close(p[1]);
	free(buf);
	return (p[0]);
}

static int		ft_get_fd_file(char *op, char *str)
{
	int			out;

	if (ft_strcmp(op, ">>") == 0)
	{
		out = open(str, O_WRONLY | O_APPEND | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	}
	else if (ft_strcmp(op, ">") == 0 || ft_strcmp(op, "&>") == 0)
	{
		out = open(str, O_WRONLY | O_TRUNC | O_CREAT,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	}
	else if (ft_strcmp(op, "<") == 0)
		out = open(str, O_RDONLY);
	else if (ft_strcmp(op, "<<") == 0)
		out = ft_str_to_fd(str);
	return (out);
}

int				ft_getfd_out(char *op, char *str)
{
	char		*nop;
	int			ret;

	nop = ft_get_type_redirect(op);
	ret = ft_atoi(str);
	if ((ret > 2 || ret < 0) && ft_strcmp(nop, "&>") != 0 &&
		ft_strcmp(nop, ">>") != 0 && ft_strcmp(nop, ">") != 0)
		return (-2);
	if ((ret == 0 && ft_strcmp(str, "0") != 0) || (ft_strcmp(nop, "&>") == 0 ||
		ft_strcmp(nop, ">>") == 0 || ft_strcmp(nop, ">") == 0))
	{
		if (ft_strcmp(str, "-") == 0)
			ret = -1;
		else
			ret = ft_get_fd_file(nop, str);
	}
	return (ret);
}
