/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_env_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 09:29:40 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/27 09:29:43 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
#include <stdio.h>

t_lstenv		*ft_lst_env_new(char **env, t_lstenv **t_env, size_t pos)
{
	char		**tmp;

	t_env[0] = (t_lstenv*)malloc(sizeof(*t_env[0]));
	if (t_env[0] != NULL)
	{
		tmp = ft_strsplit(env[pos], '=');
		t_env[0]->opt = tmp[0];
		t_env[0]->value = tmp[1];
		t_env[0]->next = NULL;
		free(tmp);
		pos++;
		if (env[pos])
			ft_lst_env_new(env, &t_env[0]->next, pos);
		else
			return (t_env[0]);
	}
	return (NULL);
}
