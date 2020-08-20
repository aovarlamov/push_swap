/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethel <kbethel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 17:54:31 by kbethel           #+#    #+#             */
/*   Updated: 2020/08/05 17:14:48 by kbethel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*separation(char *save, char ***line)
{
	int			i;
	char		*tmp;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	**line = ft_strsub(save, 0, i);
	if (save[i] == '\0' || (save[i] == '\n' && save[i + 1] == '\0'))
		ft_strdel(&save);
	else
	{
		tmp = ft_strsub(save, i + 1, ft_strlen(save) + BUFF_SIZE - i);
		free(save);
		return (tmp);
	}
	return (save);
}

char		*write_buff(char *save, char *buff)
{
	char	*tmp;

	if (save)
	{
		tmp = ft_strdup(save);
		free(save);
		save = ft_strjoin(tmp, buff);
		free(tmp);
	}
	else
		save = ft_strdup(buff);
	return (save);
}

int			get_next_line(const int fd, char **line)
{
	static char *save[MFD];
	char		buff[BUFF_SIZE + 1];
	int			rt;

	if (fd < 0 || !line || fd >= MFD)
		return (-1);
	while ((rt = read(fd, buff, BUFF_SIZE)))
	{
		if (rt == -1)
			return (-1);
		buff[rt] = '\0';
		save[fd] = write_buff(save[fd], buff);
		if (ft_strchr(buff, '\n'))
		{
			save[fd] = separation(save[fd], &line);
			return (1);
		}
	}
	if (save[fd] != NULL)
	{
		save[fd] = separation(save[fd], &line);
		return (1);
	}
	return (0);
}
