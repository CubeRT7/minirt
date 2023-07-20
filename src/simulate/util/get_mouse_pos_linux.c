/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_pos_linux.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:02:11 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/20 08:29:12 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate_util.h"

t_vector3	get_mouse_pos(t_world *world)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(world->viewport.mlx, world->viewport.win, &x, &y);
	return (vector3(x, y, 0));
}
