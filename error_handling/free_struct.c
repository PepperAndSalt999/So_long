/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 07:06:30 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 16:08:57 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../static/includes/so_long.h"

void	free_struct(t_map *map)
{
	t_map	*temp;

	if (map->line)
		free(map->line);
	if (map->next)
		map = map->next;
	while (map)
	{
		temp = map->next;
		free(map->line);
		free(map);
		map = temp;
	}
}
