/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hooks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 07:28:01 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 17:32:02 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../../static/includes/so_long.h"

int	keys(int keycode, struct s_data *data)
{
	if (keycode == 53)
		closed(data);
	if ((keycode >= 0 && keycode < 3) || keycode == 13)
	{
		data->moves++;
		ft_putstr("number of movements:");
		ft_putstr(ft_itoa(data->moves));
		write(1, "\n", 1);
		get_swap_value(keycode, &data->player, data);
	}
	return (0);
}

int	closed(struct s_data *data)
{
	quit_and_display(12, data);
	return (0);
}
