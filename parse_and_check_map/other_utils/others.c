/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   others.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 06:56:02 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 14:29:59 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../static/includes/so_long.h"

void	fill_player_store(struct s_player_store *player, int *lookup)
{
	player->to_collect = lookup['C'];
}

int	ft_strchr(char *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}
