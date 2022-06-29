/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrpere <gabrpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:53:24 by gabrpere          #+#    #+#             */
/*   Updated: 2022/06/27 04:04:45 by gabrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *str, int c)
{
	char	*x;
	int		pos;

	pos = 0;
	x = (char *)str;
	while (x[pos] != (char)c && x[pos] != '\0')
		pos++;
	if (x[pos] == '\0' && c != 0)
		return (NULL);
	return (x + pos);
}

static char	*get_line(char **line)
{
	int		i;
	char	*ret;
	char	*swap;

	if (!line[0])
		return (NULL);
	i = 0;
	if (line[0][0] == '\0')
	{
		free(line[0]);
		return (NULL);
	}
	while (line[0][i] != '\0' && line[0][i] != '\n')
		i++;
	ret = ft_substr(line[0], 0, i + (line[0][i] == '\n'));
	if (line[0][i] == '\n')
		swap = ft_strdup(line[0] + i + 1);
	else
		swap = NULL;
	free(line[0]);
	line[0] = swap;
	return (ret);
}

static void	swap(char	**buffer, char	*temp)
{
	char	*swap;

	swap = ft_strjoin(*buffer, temp);
	free (*buffer);
	*buffer = swap;
}

char	*get_next_line(int fd)
{
	char			*temp;
	static char		*buffer;
	int				read_status;

	read_status = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read_status > 0)
	{
		read_status = read(fd, temp, BUFFER_SIZE);
		if (read_status < 1 && buffer == NULL)
		{
			free(temp);
			return (NULL);
		}
		temp[read_status] = '\0';
		if (!buffer)
			buffer = ft_substr(temp, 0, BUFFER_SIZE);
		else
			swap(&buffer, temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(temp);
	return (get_line(&buffer));
}
