/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:13:07 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 18:29:07 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	_update_next_render_idx(t_device *device)
{
	device->separated_render_curr.x++;
	if (device->separated_render_curr.x >= device->separated_render_max.x)
	{
		device->separated_render_curr.x = 0;
		device->separated_render_curr.y++;
	}
	if (device->separated_render_curr.y >= device->separated_render_max.y)
		device->separated_render_curr.y = 0;
}

static int	_get_pixel(t_world *w, t_vector3 pos)
{
	static const t_vector3	v[] = {
		(t_vector3){0, 0.5, 0},
		(t_vector3){-0.5, -0.5, 0},
		(t_vector3){0.5, -0.5, 0}};
	int						idx;
	t_color					color;
	t_color					res;

	res = v3_preset(V3_ZERO);
	idx = 0;
	while (idx < 3)
	{
		color = ray_color(w, v3_add(pos, v[idx]));
		res = v3_add(res, color);
		idx++;
	}
	return (color_to_pixel(v3_mul(res, 0.333)));
}

void	render_main_frame(t_world *world)
{
	t_device *const	device = &world->device;
	t_vector3		pos;
	int				pixel_color;

	pos.x = device->separated_render_curr.x;
	while (pos.x < device->size.x)
	{
		pos.y = device->separated_render_curr.y;
		while (pos.y < device->size.y)
		{
			if (pos.x > device->size.x || pos.y > device->size.y)
				break ;
			pixel_color = _get_pixel(world, pos);
			put_pixel(device, pos.x, device->size.y - pos.y - 1, pixel_color);
			pos.y += device->separated_render_max.y;
		}
		pos.x += device->separated_render_max.x;
	}
	_update_next_render_idx(device);
}
