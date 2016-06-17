/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_argv_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 03:17:06 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/15 18:42:37 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void			ft_add_first(t_mcmd **cmd, char **argv, int i)
{
	char		**nargv;

	nargv = cmd[0]->argv;
	cmd[0]->argv = (char**)malloc(sizeof(char**) * (2));
	cmd[0]->argv[0] = ft_strdup(argv[i]);
	cmd[0]->argv[1] = 0;
	cmd[0]->argc = 2;
	free(nargv);
}

void			ft_add_argv_cmd(t_mcmd **cmd, char **argv, int i)
{
	char		**nargv;
	int			j;

	if (cmd[0]->argv[0] == 0)
		ft_add_first(cmd, argv, i);
	else
	{
		nargv = cmd[0]->argv;
		cmd[0]->argv = (char**)malloc(sizeof(char**) * (cmd[0]->argc + 1));
		j = 0;
		while (j < cmd[0]->argc - 1)
		{
			cmd[0]->argv[j] = ft_strdup(nargv[j]);
			free(nargv[j++]);
		}
		cmd[0]->argv[j] = ft_strdup(argv[i]);
		cmd[0]->argv[j + 1] = 0;
		free(nargv);
		cmd[0]->argc++;
	}
}
