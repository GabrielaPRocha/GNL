/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrpere <gabrpere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 00:53:19 by gabrpere          #+#    #+#             */
/*   Updated: 2022/06/24 03:56:30 by gabrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char const *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static int	copystr(char *dest, char const *src, int newpos)
{
	int	lensrc;
	int	pos;

	lensrc = ft_strlen(src);
	pos = 0;
	while (pos < lensrc)
	{
		dest[newpos] = src[pos];
		newpos++;
		pos++;
	}
	return (newpos);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		newpos;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	newpos = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	newpos = copystr(new, s1, newpos);
	newpos = copystr(new, s2, newpos);
	new[newpos] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (len + start > (size_t) ft_strlen(s))
		len = ft_strlen(s) - start;
	if ((int) len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > (unsigned int)ft_strlen(s))
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
	}
	str[j] = 0;
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		x;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	x = 0;
	while (src[x])
	{
		new[x] = src[x];
		x++;
	}
	new[x] = '\0';
	return (new);
}
