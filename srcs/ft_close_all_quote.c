/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_all_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 11:34:47 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:44:23 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		ft_close_bquote(t_dat *t_d, int i)
{
	char		*tmp_cmd;
	int			len;
	int			nlen;

	len = 0;
	while (t_d->cmd[i] && t_d->cmd[i] != '<' && t_d->cmd[i] != '>' &&
		t_d->cmd[i] != '&' && t_d->cmd[i] != '|')
		i++;
	if (ft_strocur_slash(t_d->cmd, '`') % 2 != 0)
	{
		t_d->prompt = "bquote>";
		while (ft_strocur_slash(t_d->cmd, '`') % 2 != 0 &&
			ft_strcmp(t_d->prompt, "bquote>") == 0)
		{
			nlen = ft_strlen(t_d->cmd);
			ft_complet_cmd(t_d, i);
			i += ft_strlen(t_d->cmd) - nlen;
			ft_stradd_slash(&t_d->cmd, '\'');
			ft_stradd_slash(&t_d->cmd, '"');
			len++;
		}
	}
	return (len);
}

static int		ft_close_dquote(t_dat *t_d, int i)
{
	char		*tmp_cmd;
	int			len;
	int			nlen;

	len = 0;
	while (t_d->cmd[i] && t_d->cmd[i] != '<' && t_d->cmd[i] != '>' &&
		t_d->cmd[i] != '&' && t_d->cmd[i] != '|')
		i++;
	if (ft_strocur_slash(t_d->cmd, '"') % 2 != 0)
	{
		t_d->prompt = "dquote>";
		while (ft_strocur_slash(t_d->cmd, '"') % 2 != 0 &&
			ft_strcmp(t_d->prompt, "dquote>") == 0)
		{
			nlen = ft_strlen(t_d->cmd);
			ft_complet_cmd(t_d, i);
			i += ft_strlen(t_d->cmd) - nlen;
			ft_stradd_slash(&t_d->cmd, '`');
			ft_stradd_slash(&t_d->cmd, '\'');
			len++;
		}
	}
	return (len);
}

static int		ft_close_quote(t_dat *t_d, int i)
{
	char		*tmp_cmd;
	int			len;
	int			nlen;

	len = 0;
	while (t_d->cmd[i] && t_d->cmd[i] != '<' && t_d->cmd[i] != '>' &&
		t_d->cmd[i] != '&' && t_d->cmd[i] != '|')
		i++;
	t_d->prompt = "quote>";
	while (ft_strocur_slash(t_d->cmd, '\'') % 2 != 0 &&
		ft_strcmp(t_d->prompt, "quote>") == 0)
	{
		nlen = ft_strlen(t_d->cmd);
		ft_complet_cmd(t_d, i);
		i += ft_strlen(t_d->cmd) - nlen;
		ft_stradd_slash(&t_d->cmd, '`');
		ft_stradd_slash(&t_d->cmd, '"');
		len++;
	}
	return (len);
}

int				ft_close_all_quote(t_dat *t_d, int i)
{
	if (((ft_strocur_slash(t_d->cmd, '"') != 0 && t_d->cmd[i] == '"') ||
		(ft_strocur_slash(t_d->cmd, '`') != 0 && t_d->cmd[i] == '`')) &&
		t_d->cmd[i - 1] != '\\')
	{
		i += ft_close_bquote(t_d, i);
		i += ft_close_dquote(t_d, i);
	}
	else if (ft_strocur_slash(t_d->cmd, '\'') != 0 && t_d->cmd[i] == '\'' &&
			t_d->cmd[i - 1] != '\\')
		i += ft_close_quote(t_d, i);
	return (i);
}
