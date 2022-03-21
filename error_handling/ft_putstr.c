/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 16:04:21 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 16:40:45 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../static/includes/so_long.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
