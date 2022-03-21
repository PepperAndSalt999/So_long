/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 07:28:57 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 15:39:50 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../static/includes/so_long.h"

int static	valid_cell(struct s_map *cell, int new_x,
	struct s_player_store *player, struct s_data *data)
{
	if (cell)
	{
		if (cell->line[new_x])
		{
			if (cell->line[new_x] == '0' || cell->line[new_x] == 'C'
				|| cell->line[new_x] == 'P')
				return (1);
			else if (cell->line[new_x] == 'E' && player->to_collect == 0)
				quit_and_display(11, data);
		}
	}
	return (0);
}

void static	swap_values(char *old_cell, char *new_cell,
	struct s_player_store *player)
{
	if (*new_cell == 'C')
		player->to_collect--;
	*new_cell = 'P';
	*old_cell = '0';
}

int	get_swap_value(int keycode, struct s_player_store *player,
	struct s_data *data)
{
	struct s_map	*cell;
	int				new_x;

	new_x = player->current_x;
	cell = player->current_cell;
	if (keycode == 0)
		new_x--;
	else if (keycode == 2)
		new_x++;
	else if (keycode == 1)
		cell = move_forward(player->current_cell);
	else if (keycode == 13)
		cell = move_backward(player->current_cell);
	if (valid_cell(cell, new_x, player, data))
	{
		swap_values(player->current_cell->line + player->current_x,
			cell->line + new_x, player);
		player->current_cell = cell;
		player->current_x = new_x;
	}
	return (1);
}
