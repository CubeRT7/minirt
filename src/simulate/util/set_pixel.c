/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 07:26:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 09:10:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate_util.h"

void	set_pixel(t_world *world, int x, int y, int color)
{
	char	*addr;
	int		size_line;
	int		bpp;
	int		endian;

	if (x < 0 || x >= world->workspace.size.x)
		return ;
	if (y < 0 || y >= world->workspace.size.y)
		return ;
	color = mlx_get_color_value(world->workspace.mlx, color);
	addr = mlx_get_data_addr(world->workspace.img, &bpp, &size_line, &endian);
	*(unsigned int *)(addr + (y * size_line + x * (bpp / 8))) = color;
}
