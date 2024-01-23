/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:57:00 by locharve          #+#    #+#             */
/*   Updated: 2024/01/22 15:53:02 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dst;

	if (!s1)
		dst = ft_strdup(s2);
	else
	{
		dst = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (!dst)
			return (NULL);
		ft_bzero(dst, ft_strlen(s1) + ft_strlen(s2) + 1);
		dst = ft_strcat_dst(dst, s1, s2);
		free(s1);
		s1 = NULL;
	}
	return (dst);
}

char	*ft_read_file(char *line, int fd)
{
	char	*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_bzero(buf, BUFFER_SIZE + 1);
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buf);
		if (!line)
			return (NULL);
		if (ft_strchr(line, '\n'))
			break ;
		ft_bzero(buf, BUFFER_SIZE + 1);
	}
	free(buf);
	buf = NULL;
	return (line);
}

char	*ft_fill_line(char *new_l, int fd)
{
	char	*line;

	line = NULL;
	if (new_l)
	{
		line = ft_strdup(new_l);
		free(new_l);
		new_l = NULL;
		if (!line)
			return (NULL);
	}
	if (!ft_strchr(line, '\n'))
	{
		line = ft_read_file(line, fd);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*ft_strcut(char *src, int c)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i] && src[i] != c)
		i++;
	if (src[i] == '\n')
		i++;
	dst = (char *)malloc((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	free(src);
	return (dst);
}

char	*get_next_line(int fd)
{
	static char	*new_l[1024] = {NULL};
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_fill_line(new_l[fd], fd);
	if (!line)
		return (NULL);
	new_l[fd] = ft_strchr(line, '\n');
	if (new_l[fd])
	{
		new_l[fd] = ft_strdup(new_l[fd]);
		if (!new_l[fd])
			return (NULL);
		line = ft_strcut(line, '\n');
		if (!line)
			return (NULL);
	}
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
	}
	return (line);
}
