/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_characters.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 06:45:54 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 15:35:21 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../static/includes/so_long.h"

void	fill_store(struct s_map_validator_store *store, t_map *map,
					struct s_player_store *player, struct s_data *data)
{
	int	i;

	i = 0;
	while (map->line[i])
	{
		if (!ft_strchr("01PEC", map->line[i]))
			quit_and_display(5, data);
		if (map->line[i] == 'P')
		{
			player->current_cell = map;
			player->current_x = i;
		}
		store->lookup[(int)map->line[i]] += 1;
		i++;
	}
}

void	is_valid(int *lookup, struct s_data *data)
{
	if (lookup['P'] != 1 || lookup['E'] < 1 || lookup['C'] < 1)
		quit_and_display(6, data);
}

void	is_wall(t_map *map, struct s_data *data)
{
	int	i;

	i = 0;
	while (map->line[i])
	{
		if (map->line[i] != '1')
			quit_and_display(7, data);
		i++;
	}
}

void	are_limits_wall(int length, t_map *map, struct s_data *data)
{
	if (map->line[0] != '1' || map->line[length - 1] != '1')
		quit_and_display(8, data);
}

int	check_length(int prev_length, t_map *map, struct s_data *data)
{
	int	i;

	i = 0;
	while (map->line[i])
		i++;
	if (prev_length == 0)
	{
		if (!i)
			quit_and_display(9, data);
	}
	else if (prev_length != i)
		quit_and_display(9, data);
	return (i);
}
