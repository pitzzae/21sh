/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 11:02:42 by gtorresa          #+#    #+#             */
/*   Updated: 2016/03/27 11:02:43 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_lst_add_env(t_lstenv **t_env, char *opt, char *value)
{
	t_lstenv			*t_envtmp;

	t_envtmp = (*t_env);
	while (t_envtmp->next)
		t_envtmp = t_envtmp->next;
	t_envtmp->next = (t_lstenv*)malloc(sizeof(*t_env[0]));
	if (t_envtmp->next != NULL)
	{
		t_envtmp = t_envtmp->next;
		t_envtmp->opt = opt;
		t_envtmp->value = value;
		t_envtmp->next = NULL;
	}
	return (NULL);
}
