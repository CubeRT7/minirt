/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mouse_pos_macos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:02:11 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/20 08:29:15 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "device.h"

t_vector3	get_mouse_pos(t_device *device)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(device->win, &x, &y);
	return (vector3(x, y, 0));
}
