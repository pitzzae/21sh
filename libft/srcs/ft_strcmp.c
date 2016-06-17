/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 21:04:39 by gtorresa          #+#    #+#             */
/*   Updated: 2015/12/07 15:35:01 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int count;

	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0')
		count++;
	return (((unsigned char)s1[count] - (unsigned char)s2[count]));
}
