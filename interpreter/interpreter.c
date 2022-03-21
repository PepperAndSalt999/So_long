/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interpreter.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 07:21:10 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 15:58:28 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../static/includes/so_long.h"

void	interpret_map(struct s_data *data)
{
	render(data);
	mlx_hook(data->mlx.mlx_win, 2, 0, keys, data);
	mlx_hook(data->mlx.mlx_win, 17, 0, closed, data);
	mlx_loop_hook(data->mlx.mlx, render, data);
	mlx_loop(data->mlx.mlx);
}
