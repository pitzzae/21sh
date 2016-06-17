/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 08:38:32 by gtorresa          #+#    #+#             */
/*   Updated: 2016/06/11 19:27:33 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int				main(int argc, char **argv, char **env)
{
	t_dat		t_d;
	char		**newenv;

	t_d.argv = argv;
	if (ft_init_env(&newenv, env) == 0 && argc > 0)
		ft_lst_env_new(env, &t_d.t_env, 0);
	else
	{
		ft_lst_env_new(newenv, &t_d.t_env, 0);
		free(newenv[0]);
		free(newenv[1]);
		free(newenv[2]);
		free(newenv);
	}
	ft_update_shlvl(&t_d.t_env);
	ft_lst_to_env(&t_d.t_env, &newenv, 0);
	t_d.env = newenv;
	ft_init_history(&t_d);
	signal(SIGINT, get_sigint);
	if (!ft_init_termios(&t_d, 1))
		return (-1);
	while (ft_initshell(&t_d, t_d.init_p) == 1)
		;
	return (0);
}
