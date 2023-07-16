/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:26:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/17 07:26:18 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate_util.h"

void	set_pixel(t_world *world, int x, int y, int color)
{
	char	*addr;
	int		size_line;
	int		bpp;
	int		endian;

	if (x < 0 || y < 0 || x >= world->gui.screen.x || y >= world->gui.screen.y)
		return ;
	color = mlx_get_color_value(world->gui.mlx, color);
	addr = mlx_get_data_addr(world->gui.img, &bpp, &size_line, &endian);
	*(unsigned int *)(addr + (y * size_line + x * (bpp / 8))) = color;
}
