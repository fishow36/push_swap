/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrogg <mbrogg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:44:35 by mbrogg            #+#    #+#             */
/*   Updated: 2019/11/19 21:21:25 by mbrogg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
**	Check descriptor and allocate memory for line
**	so we don't know whether memory static or dynamic in line
**	Also there is null for pointer temp in func get_next_line
**	If check is passed the func returns (1), otherwise (0)
*/

char	*fill_line(char *r_fd, char **line)
{
	char *tmp;

	tmp = r_fd;
	if ((ft_strchr(r_fd, '\n')))
	{
		*line = ft_strsub(r_fd, 0,
		ft_strlen(r_fd) - ft_strlen(ft_strchr(r_fd, '\n')));
		if (!(r_fd = ft_strchr(r_fd, '\n')) ||
		!(r_fd = ft_strsub(r_fd, 1, ft_strlen(r_fd) - 1)))
			return (NULL);
	}
	else
	{
		*line = ft_strdup(r_fd);
		r_fd = ft_strdup("");
		if (!(*line) || !r_fd)
			return (NULL);
	}
	ft_strdel(&tmp);
	return (r_fd);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*r[MAX_FD];
	ssize_t		ret;
	char		*tmp;

	if (fd < 0 || fd > MAX_FD || !line || (!r[fd] && !(r[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(r[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = r[fd];
		buf[ret] = '\0';
		if (!(r[fd] = ft_strjoin(r[fd], buf)))
			return (-1);
		ft_strdel(&tmp);
	}
	if (ret == -1 || !r[fd])
		return (-1);
	if (ft_strcmp(r[fd], "") == 0 && ret == 0)
		return (0);
	if ((r[fd] = fill_line(r[fd], line)) == NULL)
		return (-1);
	return (1);
}
