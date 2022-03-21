/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_display.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 06:05:51 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 16:31:50 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../static/includes/so_long.h"

char	**init_error_tab(char **lookup)
{
	lookup[0] = "wrong number of arguments";
	lookup[1] = "this is not a .ber file";
	lookup[2] = "there was a problem reading the file";
	lookup[3] = "the malloc failed for a new node";
	lookup[5] = "wrong map, there's a forbidden character";
	lookup[6] = "wrong map, there's not the mandatory number of characters";
	lookup[7] = "wrong map, the first and last row of walls are imcomplete";
	lookup[8] = "wrong map, the first and last columns of walls are imcomplete";
	lookup[9] = "wrong map, this is not a rectangle";
	lookup[10] = "couldn't load imgs";
	lookup[11] = "game finished";
	lookup[12] = "you closed the game";
	lookup[13] = 0;
	return (lookup);
}

void	destroy_images(void *mlx, struct s_imgs *imgs)
{
	if (imgs->collectible.img)
		mlx_destroy_image(mlx, imgs->collectible.img);
	if (imgs->exit.img)
		mlx_destroy_image(mlx, imgs->exit.img);
	if (imgs->character.img)
		mlx_destroy_image(mlx, imgs->character.img);
	if (imgs->empty.img)
		mlx_destroy_image(mlx, imgs->empty.img);
	if (imgs->wall.img)
		mlx_destroy_image(mlx, imgs->wall.img);
}

void	quit_and_display(int code, struct s_data *data)
{
	char	*lookup[14];

	init_error_tab(lookup);
	if (code <= 10)
		ft_putstr("Error\n");
	ft_putstr(lookup[code]);
	if (code >= 2)
		free_struct(&data->map);
	if (code >= 10)
	{
		destroy_images(data->mlx.mlx, &data->imgs);
		mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	}
	if (code >= 11)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	process_error(void)
{
	ft_putstr("Error\n");
	perror("failed");
	exit(EXIT_FAILURE);
}
