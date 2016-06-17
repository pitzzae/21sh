/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:28:41 by gtorresa          #+#    #+#             */
/*   Updated: 2015/12/02 14:31:52 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(long int n, int fd)
{
	long int	i;

	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	i = n - (n % 10);
	if (i > 0)
		ft_putnbr_fd(i / 10, fd);
	i = (n % 10) + 48;
	write(fd, &i, 1);
}
