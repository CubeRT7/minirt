/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:13:07 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/19 15:13:08 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	_update_next_render_idx(t_gui_setting *gui)
{
	gui->separated_render_curr.x++;
	if (gui->separated_render_curr.x >= gui->separated_render_max.x)
	{
		gui->separated_render_curr.x = 0;
		gui->separated_render_curr.y++;
	}
	if (gui->separated_render_curr.y >= gui->separated_render_max.y)
		gui->separated_render_curr.y = 0;
}

static int	_get_pixel(t_world *world, t_vector3 pos)
{
	t_color	color;
	t_ray	ray;

	ray = get_camera_ray(world->camera, world->gui.screen, pos);
	color = ray_color(&ray, world->objs, world->ambient_light, world->lights);
	return (color_to_pixel(color));
}

void	render_main_frame(t_world *world)
{
	t_gui_setting *const	gui = &world->gui;
	t_vector3				pos;
	int						pixel_color;

	pos.x = gui->separated_render_curr.x;
	while (pos.x < gui->screen.x)
	{
		pos.y = gui->separated_render_curr.y;
		while (pos.y < gui->screen.y)
		{
			if (pos.x > gui->screen.x || pos.y > gui->screen.y)
				break ;
			pixel_color = _get_pixel(world, pos);
			set_pixel(world, pos.x, gui->screen.y - pos.y - 1, pixel_color);
			pos.y += gui->separated_render_max.y;
		}
		pos.x += gui->separated_render_max.x;
	}
	_update_next_render_idx(gui);
}
