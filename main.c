/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 06:55:08 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 17:35:21 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./static/includes/so_long.h"

int	main(int argc, char **argv)
{
	struct s_data	data;

	data.moves = 0;
	if (argc == 2)
	{
		init_lookup(data.map_validator.lookup);
		parse_and_check_map(argv[1], &data, argv[1]);
		init_mlx(&data.mlx, &data.window);
		init_img(&data.imgs, &data.mlx, &data);
		interpret_map(&data);
	}
	quit_and_display(0, &data);
	return (0);
}
