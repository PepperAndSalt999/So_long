/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 07:40:01 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 17:26:44 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_map
{
	int		row;
	char	*line;
	void	*next;
	void	*prev;
}	t_map;

struct	s_player_store
{
	int		to_collect;
	int		current_x;
	t_map	*current_cell;
};

struct	s_map_validator_store
{
	int	lookup[127];
	int	rectangular;
};

struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
};

struct s_img
{
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_imgs
{
	struct s_img	character;
	struct s_img	collectible;
	struct s_img	exit;
	struct s_img	start;
	struct s_img	empty;
	struct s_img	wall;
	void			*img_to_print;
	int				imgs_width;
	int				imgs_height;
};

struct s_window
{
	int	column;
	int	row;
};

struct s_data
{
	t_map							map;
	struct s_mlx					mlx;
	struct s_imgs					imgs;
	struct s_window					window;
	struct s_player_store			player;
	struct s_map_validator_store	map_validator;
	int								moves;
};

void	read_and_store(int fd, t_map *map, struct s_data *data);
void	check_map(struct s_data *data);
void	free_struct(t_map *map);
int		closed(struct s_data *data);
void    ft_putstr(char *str);
char	*ft_itoa(int n);

//get rid of errors
void	process_error(void);
void	free_struct(t_map *map);
void	destroy_images(void *mlx, struct s_imgs *imgs);
void	quit_and_display(int code, struct s_data *data);

//init data structures
void	fill_player_store(struct s_player_store *player, int *lookup);
void	init_lookup(int *lookup);

//Parse map
void	parse_and_check_map(char *map, struct s_data *data, char *argv);

//initialise the lib
void	init_mlx(struct s_mlx *init, struct s_window *window);
void	init_img(struct s_imgs *imgs, struct s_mlx *mlx, struct s_data *data);

//interpreter
void	interpret_map(struct s_data *data);
int		render(struct s_data *data);

//map utils
void	add_forward_row(t_map *cell, char *newline, struct s_data *data);
void	add_row(t_map *cell, char *newline);
void	update_cells(char **old_cell, char **new_cell);
t_map	*move_backward(t_map *cell);
t_map	*move_forward(t_map *cell);


//map validator utils
void	is_wall(t_map *map, struct s_data *data);
void	is_valid(int *lookup, struct s_data *data);
void	are_limits_wall(int length, t_map *map, struct s_data *data);
int		check_length(int prev_length, t_map *map, struct s_data *data);
void	check_extension(char *string, struct s_data *data);
void	fill_store(struct s_map_validator_store *store, t_map *cell,
			struct s_player_store *player, struct s_data *data);

//others
int		ft_strchr(char *set, char c);

//get_next_line
char	*get_next_line(int fd);
char	*ft_strdup(char *string, int free_me, int super_len);
char	*newline(char *store);
char	*ft_calloc(int len);
int		ft_strcpy(char *dest, char *src, int len);
size_t	ft_strlen_bzero(char *string, int choice, int len);

//hooks
int		keys(int keycode, struct s_data *data);
int		close_window(int keycode, struct s_mlx *mlx);

//hooks_utils
int		get_swap_value(int keycode, struct s_player_store *player, struct s_data *data);

//lookup
#endif