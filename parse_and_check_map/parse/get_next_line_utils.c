/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 15:47:24 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 14:29:47 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../static/includes/so_long.h"

size_t	ft_strlen_bzero(char *string, int choice, int len)
{
	int	i;

	i = 0;
	if (choice == 1)
	{
		if (!string)
			return (0);
		while (string[i])
			i++;
	}
	else
	{
		while (i < len)
		{
			string[i] = '\0';
			i++;
		}
	}
	return (i);
}

char	*ft_strdup(char *string, int free_me, int super_len)
{
	int		i;
	int		len;
	char	*cpy_string;

	i = 0;
	cpy_string = NULL;
	len = ft_strlen_bzero(string, 1, 0);
	if (!(super_len == -1))
		len = super_len;
	cpy_string = ft_calloc(len);
	if (!cpy_string)
		return (NULL);
	ft_strcpy(cpy_string, string, len);
	if (free_me)
		free(string);
	return (cpy_string);
}

char	*newline(char *store)
{
	while (*store)
	{
		if (*store == '\n')
			return (store);
		store++;
	}
	return (NULL);
}

int	ft_strcpy(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	if (len <= 0)
		len = ft_strlen_bzero(src, 1, 0);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

char	*ft_calloc(int len)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	ft_strlen_bzero(buf, 2, len + 1);
	return (buf);
}
