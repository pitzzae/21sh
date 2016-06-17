/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtorresa <gtorresa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 00:52:34 by gtorresa          #+#    #+#             */
/*   Updated: 2016/02/11 12:30:18 by gtorresa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		last_line_join(char buf[BUF_SIZE + 1], char **line)
{
	char			*tmp;

	tmp = ft_strsub(buf, 0, ft_strfocur(buf, '\n'));
	line[0] = ft_strjoin_free(line[0], tmp, 3);
	tmp = ft_strsub(buf, ft_strfocur(buf, '\n') + 1, BUF_SIZE);
	ft_bzero(buf, BUF_SIZE);
	ft_strcpy(buf, tmp);
	free(tmp);
}

static void		init_line(char **line)
{
	if (line[0] == NULL)
	{
		line[0] = (char*)malloc(sizeof(line[0]) * 2);
		ft_strcpy(line[0], "");
	}
	else
	{
		line[0] = NULL;
		init_line(line);
	}
}

static int		read_fd(int const fd, char **line)
{
	static char		buf[FD_SIZE][BUF_SIZE + 1];
	int				ret;

	if (ft_strlen(buf[fd]) == 0)
	{
		ret = read(fd, buf[fd], BUF_SIZE);
		buf[fd][ret] = '\0';
		if (ret == 0 || ret == -1)
			return (ret);
	}
	if (ft_strfocur(buf[fd], '\n') == -1)
	{
		line[0] = ft_strjoin_free(line[0], buf[fd], 1);
		ft_bzero(buf[fd], BUF_SIZE);
		read_fd(fd, line);
	}
	else
		last_line_join(buf[fd], line);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;

	ret = -1;
	if (line == NULL)
		return (ret);
	if (fd < FD_SIZE && fd >= 0)
	{
		init_line(line);
		ret = read_fd(fd, line);
	}
	return (ret);
}
