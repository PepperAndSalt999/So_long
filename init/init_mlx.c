/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 07:08:49 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 07:12:19 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../static/includes/so_long.h"

void	init_mlx(struct s_mlx *init, struct s_window *window)
{
	init->mlx = mlx_init();
	init->mlx_win = mlx_new_window(init->mlx, window->column * 35,
			window->row * 35, "So_long");
}
