/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moving.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 06:51:31 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 15:50:55 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../static/includes/so_long.h"

void	add_row(t_map *cell, char *newline)
{
	cell->line = newline;
}

void	add_forward_row(t_map *map, char *newline, struct s_data *data)
{
	t_map	*new_cell;

	new_cell = (t_map *)malloc(sizeof(t_map));
	if (!new_cell)
		quit_and_display(3, data);
	new_cell->prev = map;
	new_cell->next = NULL;
	new_cell->line = newline;
	map->next = new_cell;
	map = map->next;
}

t_map	*move_backward(t_map *cell)
{
	cell = cell->prev;
	return (cell);
}

t_map	*move_forward(t_map *cell)
{
	cell = cell->next;
	return (cell);
}
