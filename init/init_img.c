/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_img.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 07:15:23 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 15:35:59 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../static/includes/so_long.h"

void	init_img(struct s_imgs *imgs, struct s_mlx *mlx, struct s_data *data)
{
	imgs->imgs_width = 35;
	imgs->imgs_height = 35;
	imgs->collectible.img = mlx_xpm_file_to_image(mlx->mlx,
			"./static/pictures/collectible.xpm", &imgs->imgs_width,
			&imgs->imgs_height);
	imgs->start.img = mlx_xpm_file_to_image(mlx->mlx,
			"./static/pictures/character.xpm",
			&imgs->imgs_width, &imgs->imgs_height);
	imgs->empty.img = mlx_xpm_file_to_image(mlx->mlx,
			"./static/pictures/empty.xpm",
			&imgs->imgs_width, &imgs->imgs_height);
	imgs->exit.img = mlx_xpm_file_to_image(mlx->mlx,
			"./static/pictures/exit.xpm",
			&imgs->imgs_width, &imgs->imgs_height);
	imgs->wall.img = mlx_xpm_file_to_image(mlx->mlx,
			"./static/pictures/wall.xpm",
			&imgs->imgs_width, &imgs->imgs_height);
	if (!(imgs->collectible.img && imgs->start.img
			&& imgs->empty.img && imgs->exit.img && imgs->wall.img))
		quit_and_display(10, data);
}
