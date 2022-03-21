/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 13:57:39 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 16:40:58 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../static/includes/so_long.h"

static void	*get_image(char c, struct s_imgs *imgs)
{
	if (c == 'C')
		return (imgs->collectible.img);
	else if (c == 'E')
		return (imgs->exit.img);
	else if (c == 'P')
		return (imgs->start.img);
	else if (c == '0')
		return (imgs->empty.img);
	else if (c == '1')
		return (imgs->wall.img);
	return (NULL);
}

void static	print_images(struct s_mlx *library, struct s_imgs *imgs,
	struct s_map *map, int j)
{
	int	offset;
	int	i;

	i = 0;
	offset = 0;
	while (map->line[i])
	{
		mlx_put_image_to_window(library->mlx, library->mlx_win,
			get_image('0', imgs), i * 35, j * 35);
		if (map->line[i] != '0')
		{
			if (map->line[i] == 'C')
				offset = 10;
			mlx_put_image_to_window(library->mlx, library->mlx_win,
				get_image(map->line[i], imgs),
				i * 35 + offset, j * 35 + 10);
			offset = 0;
		}
		i++;
	}
}

int	render(struct s_data *data)
{
	int		j;
	t_map	*map;

	map = &data->map;
	j = 0;
	while (map)
	{
		print_images(&data->mlx, &data->imgs, map, j);
		j++;
		map = move_forward(map);
	}
	return (0);
}
