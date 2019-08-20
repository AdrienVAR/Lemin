/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: advardon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:35:56 by advardon          #+#    #+#             */
/*   Updated: 2019/08/19 17:58:34 by advardon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			free_static(int fd, int ret_value, char **str)
{
	if (fd == -2)
	{
		while (ret_value < 4867)
		{
			free(str[ret_value]);
			ret_value++;
		}
		return (1);
	}
	return (0);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	int		size;
	char	*tmp;

	size = ft_strlen(s1);
	if (!(tmp = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ft_memcpy(tmp, s1, n);
	tmp[n] = '\0';
	return (tmp);
}

static int	ref_line_statstr(char **line, char **str)
{
	size_t	n;
	char	*tmp;

	tmp = *str;
	n = 0;
	while (tmp[n] != '\n')
	{
		if (tmp[n] == '\0')
			return (0);
		n++;
	}
	if (!(*line = ft_strndup(*str, n)))
		return (-1);
	if (!(*str = ft_strdup(&tmp[n + 1])))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}

static int	read_bsize(const int fd, char **line, char **str, char *buf)
{
	char	*tmp;
	int		ret;
	int		i;

	while ((ret = read(fd, buf, BUFF_SIZE_GNL)) > 0)
	{
		buf[ret] = '\0';
		if (*str)
		{
			tmp = *str;
			if (!(*str = ft_strjoin(tmp, buf)))
				return (-1);
			ft_strdel(&tmp);
		}
		else if (!(*str = ft_strdup(buf)))
			return (-1);
		i = 0;
		i = ref_line_statstr(line, str);
		if (i != 0)
			return (i);
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	int			ret_value;
	char		buf[BUFF_SIZE_GNL + 1];
	static char	*str[4867];

	ret_value = 0;
	if (free_static(fd, ret_value, str))
		return (1);
	if (line == NULL || fd < 0 || fd > 4867 || BUFF_SIZE_GNL < 1)
		return (-1);
	if (str[fd])
	{
		if (ref_line_statstr(line, &str[fd]) == 1)
			return (1);
	}
	ret_value = read_bsize(fd, line, &str[fd], buf);
	if (ret_value == -1 || !str[fd] || str[fd][0] == '\0')
		return (ret_value);
	if (ret_value == 0 && str[fd])
	{
		*line = str[fd];
		str[fd] = NULL;
	}
	return (1);
}
