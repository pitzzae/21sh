/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_read_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 16:59:15 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:46:06 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_openclose_char(char *cmd, char *eof, int pos, int max)
{
	int		i;
	int		j;
	int		k;

	i = pos;
	j = 0;
	while (cmd[i] && i < max)
	{
		k = 0;
		while (eof[k] && cmd[i + k] == eof[k])
			k++;
		if (k == ft_strlen(eof))
			j++;
		i++;
	}
	return (j);
}

static char		*ft_get_eof(t_dat *t_d, int pos)
{
	char	*eof;
	int		i;

	i = 0;
	eof = ft_strsub(t_d->cmd, pos, ft_strlen(t_d->cmd) - pos);
	while (eof[i] && eof[i] == ' ')
		i++;
	eof = ft_strsub_free(eof, i, ft_strlen(eof) - i, 1);
	t_d->cmd = ft_strjoin_free(ft_strsub(t_d->cmd, 0, pos),
		ft_strsub_free(t_d->cmd, pos + i, ft_strlen(t_d->cmd) - (pos + i), 1),
		3);
	i = 0;
	while (eof[i] && eof[i] != ' ')
		i++;
	eof = ft_strsub_free(eof, 0, i, 1);
	return (eof);
}

int				ft_close_read_input(t_dat *t_d, int i)
{
	char	*eof;
	char	*tmp;
	size_t	add_char;
	int		j[3];

	j[0] = 0;
	j[1] = i + 2;
	t_d->prompt = "heredoc>";
	eof = ft_get_eof(t_d, i + 2);
	add_char = ft_strlen(t_d->cmd);
	j[2] = ft_openclose_char(t_d->cmd, eof, j[1], ft_strlen(eof) + j[1]);
	while (j[2] != 2 && ft_strcmp(t_d->prompt, "heredoc>") == 0)
	{
		ft_complet_cmd(t_d, i + 2 + ft_strlen(eof) + 1);
		i += ft_strlen(t_d->cmd) - add_char;
		j[2] = ft_openclose_char(t_d->cmd, eof, j[1], ft_strlen(eof) + i + 2);
		add_char = ft_strlen(t_d->cmd);
		j[0]++;
	}
	free(eof);
	return (j[0]);
}
