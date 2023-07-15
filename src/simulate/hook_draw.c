/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/15 12:51:47 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "simulate/util/simulate_util.h"
#include "simulate/draw/draw.h"

static void	set_pixel(t_world *world, int x, int y, int color)
{
	char	*addr;
	int		size_line;
	int		bpp;
	int		endian;

	if (x < 0 || y < 0 || x >= world->gui.width || y >= world->gui.height)
		return ;
	color = mlx_get_color_value(world->gui.mlx, color);
	addr = mlx_get_data_addr(world->gui.img, &bpp, &size_line, &endian);
	*(unsigned int *)(addr + (y * size_line + x * (bpp / 8))) = color;
}

int	hook_draw(void *param)
{
	t_world *const			world = param;
	t_gui_setting *const	gui = &world->gui;
	t_screen				screen;
	t_screen				pos;
	t_ray					ray;

	hook_draw_setting(param);
	screen.w = gui->width;
	screen.h = gui->height;
	pos.x = 0;
	while (pos.x < screen.w)
	{
		pos.y = 0;
		while (pos.y < screen.h)
		{
			ray = get_camera_ray(world->camera, screen, pos);
			set_pixel(world, pos.x, screen.h - pos.y - 1,
				color_to_pixel(ray_color(&ray,
						world->objs, world->ambient_light, world->lights)));
			++pos.y;
		}
		++pos.x;
	}
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	return (EXIT_SUCCESS);
}
