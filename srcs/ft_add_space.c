/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:36:10 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/07 16:59:18 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void			ft_add_space_pipe(char **cmd)
{
	char		*tmp;
	int			pos;

	pos = 1;
	while (cmd[0][pos])
	{
		if (cmd[0][pos] == '|')
		{
			if (cmd[0][pos - 1] != ' ')
			{
				tmp = ft_strjoin_free(" ",
					ft_strsub(cmd[0], pos, ft_strlen(cmd[0]) - pos), 2);
				cmd[0] = ft_strjoin_free(ft_strsub_free(cmd[0], 0, pos, 1),
					tmp, 3);
				pos++;
			}
			while (cmd[0][pos] && cmd[0][pos] == '|')
				pos++;
			tmp = ft_strjoin_free(" ",
				ft_strsub(cmd[0], pos, ft_strlen(cmd[0]) - pos), 2);
			cmd[0] = ft_strjoin_free(ft_strsub_free(cmd[0], 0, pos, 1), tmp, 3);
			cmd[0] = ft_strjoin_free(cmd[0], " ", 1);
		}
		pos++;
	}
}

static void			ft_add_space_redir(char **cmd)
{
	char		*tmp;
	int			pos;

	pos = 1;
	while (cmd[0][pos])
	{
		if (cmd[0][pos] == '>' && cmd[0][pos - 1] != '>')
		{
			while (cmd[0][pos] && (cmd[0][pos] == '&' || cmd[0][pos] == '>'))
				pos++;
			tmp = ft_strjoin_free(" ",
				ft_strsub(cmd[0], pos, ft_strlen(cmd[0]) - pos), 2);
			cmd[0] = ft_strjoin_free(ft_strsub_free(cmd[0], 0, pos, 1), tmp, 3);
			cmd[0] = ft_strjoin_free(cmd[0], " ", 1);
		}
		pos++;
	}
}

static void			ft_add_space_redirr(char **cmd)
{
	char		*tmp;
	int			pos;

	pos = 1;
	while (cmd[0][pos])
	{
		if (cmd[0][pos] == '<')
		{
			while (cmd[0][pos] && cmd[0][pos] == '<')
				pos++;
			tmp = ft_strjoin_free(" ",
				ft_strsub(cmd[0], pos, ft_strlen(cmd[0]) - pos), 2);
			cmd[0] = ft_strjoin_free(ft_strsub_free(cmd[0], 0, pos, 1), tmp, 3);
			cmd[0] = ft_strjoin_free(cmd[0], " ", 1);
		}
		pos++;
	}
}

static void			ft_add_space_next(char **cmd)
{
	char		*tmp;
	int			pos;

	pos = 1;
	while (cmd[0][pos])
	{
		if (cmd[0][pos] == '&' && cmd[0][pos + 1] != '>')
		{
			if (cmd[0][pos - 1] != ' ' && cmd[0][pos - 1] != '>')
			{
				tmp = ft_strjoin_free(" ",
					ft_strsub(cmd[0], pos, ft_strlen(cmd[0]) - pos), 2);
				cmd[0] = ft_strjoin_free(ft_strsub_free(cmd[0], 0, pos, 1),
					tmp, 3);
				pos++;
			}
			while (cmd[0][pos] && (cmd[0][pos] == '&' || cmd[0][pos] == '>'))
				pos++;
			tmp = ft_strjoin_free(" ",
				ft_strsub(cmd[0], pos, ft_strlen(cmd[0]) - pos), 2);
			cmd[0] = ft_strjoin_free(ft_strsub_free(cmd[0], 0, pos, 1), tmp, 3);
			cmd[0] = ft_strjoin_free(cmd[0], " ", 1);
		}
		pos++;
	}
}

void				ft_add_space(char **cmd)
{
	ft_add_space_pipe(cmd);
	ft_add_space_redir(cmd);
	ft_add_space_redirr(cmd);
	ft_add_space_next(cmd);
}
