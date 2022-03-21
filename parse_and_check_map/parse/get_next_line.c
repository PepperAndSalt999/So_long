/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 15:47:05 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 14:29:43 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../static/includes/so_long.h"

static char	*ft_strjoin(char *store, char *buf, unsigned int bytes_read)
{
	int		bytes_to_alloc;
	int		i;
	char	*newstore;

	newstore = NULL;
	bytes_to_alloc = ft_strlen_bzero(store, 1, 0) + bytes_read;
	if (bytes_read == 0)
		return (store);
	newstore = ft_calloc(bytes_to_alloc);
	if (!newstore)
		return (NULL);
	i = ft_strcpy(newstore, store, -1);
	ft_strcpy(newstore + i, buf, -1);
	free(store);
	return (newstore);
}

static char	*get_newline(char **store, char *buf)
{
	char	*nl_index;
	char	*newline_found;
	char	*newstore;

	nl_index = newline(*store);
	newstore = ft_strdup(nl_index + 1, 0, ft_strlen_bzero(nl_index + 1, 1, 0));
	newline_found = ft_strdup(*store, 0, nl_index - *store);
	free(*store);
	free(buf);
	if (!(newstore || newline_found))
	{
		if (!newstore)
			free(newline_found);
		if (!newline_found)
			free(newstore);
		return (NULL);
	}
	if (!newstore[0])
	{
		free(newstore);
		newstore = NULL;
	}
	*store = newstore;
	return (newline_found);
}

static char	*loop_until_empty(int fd, char *buf, char **store, int bytes_read)
{
	char	*temp;

	while (1)
	{
		ft_strlen_bzero(buf, 2, 100 + 1);
		if (newline(*store))
			return (get_newline(store, buf));
		else if (bytes_read == 0)
		{
			free(buf);
			if (*store != 0)
			{
				temp = ft_strdup(*store, 1, -1);
				*store = NULL;
				return (temp);
			}
			free(*store);
			return (NULL);
		}
		bytes_read = read(fd, buf, 100);
		if (bytes_read > 0)
			*store = ft_strjoin(*store, buf, bytes_read);
	}
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			bytes_read;
	static char	*stores[OPEN_MAX];

	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	buf = ft_calloc(100);
	if (!buf)
		return (NULL);
	bytes_read = read(fd, buf, 100);
	if (bytes_read < 0 || (bytes_read == 0 && stores[fd] == NULL))
	{
		free(buf);
		return (NULL);
	}
	else if (bytes_read != 0)
		stores[fd] = ft_strjoin(stores[fd], buf, bytes_read);
	if (!stores[fd])
	{
		free(buf);
		return (NULL);
	}
	return (loop_until_empty(fd, buf, &(stores[fd]), bytes_read));
}
