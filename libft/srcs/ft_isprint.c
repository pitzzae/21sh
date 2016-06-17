/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 22:16:14 by gtorresa          #+#    #+#             */
/*   Updated: 2015/11/27 10:56:08 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isprint(int c1)
{
	if (c1 >= 32 && c1 <= 126)
		return (1);
	return (0);
}