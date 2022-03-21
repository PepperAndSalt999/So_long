/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_lookup.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/21 07:13:36 by rpicot        #+#    #+#                 */
/*   Updated: 2022/03/21 14:10:22 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../static/includes/so_long.h"

void	init_lookup(int *lookup)
{
	int	i;

	i = 0;
	while (i < 127)
	{
		lookup[i] = 0;
		i++;
	}
}
