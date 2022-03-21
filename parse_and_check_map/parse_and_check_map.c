/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_and_check_map.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 06:57:40 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 15:45:54 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../static/includes/so_long.h"
#include <fcntl.h>

static int	get_fd(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		process_error();
	return (fd);
}

void	read_and_store(int fd, struct s_map *map, struct s_data *data)
{
	t_map	*head;
	char	*newline;

	head = map;
	newline = get_next_line(fd);
	if (!newline)
		quit_and_display(2, data);
	add_row(map, newline);
	map->prev = NULL;
	while (newline)
	{
		newline = get_next_line(fd);
		if (newline)
		{
			add_forward_row(map, newline, data);
			map = move_forward(map);
		}
		else if (newline < 0)
			quit_and_display(2, data);
	}
	map->next = NULL;
}

void	check_map(struct s_data *data)
{
	int		prev_length;
	t_map	*head;
	t_map	*map;

	prev_length = 0;
	map = &data->map;
	head = &data->map;
	data->window.row = 1;
	is_wall(map, data);
	while (map->next)
	{
		prev_length = check_length(prev_length, map, data);
		are_limits_wall(prev_length, map, data);
		fill_store(&data->map_validator, map, &data->player, data);
		map = move_forward(map);
		data->window.row++;
	}
	data->window.column = prev_length;
	is_wall(map, data);
	is_valid(data->map_validator.lookup, data);
}

void	check_extension(char *string, struct s_data *data)
{
	char	*verif;
	int		i;
	int		j;

	i = 0;
	j = 0;
	verif = ".ber";
	while (string[i])
	{
		while (verif[j] == string[i + j])
		{
			if (!verif[j])
				return ;
			j++;
		}
		j = 0;
		i++;
	}
	quit_and_display(1, data);
}

void	parse_and_check_map(char *map, struct s_data *data, char *argv)
{
	int	fd;

	check_extension(argv, data);
	fd = get_fd(map);
	read_and_store(fd, &data->map, data);
	check_map(data);
	fill_player_store(&data->player, data->map_validator.lookup);
}
