/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:13:07 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/31 08:21:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "miniRT_bonus.h"
#define THREAD_COUNT 8

static void	_update_next_render_idx(t_device *device)
{
	device->separated_render_curr.x += THREAD_COUNT;
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

static void	*_render_image(void *data)
{
	t_world_for_thread *const	wft = data;
	t_device *const				device = &wft->world->device;
	t_vector3					pos;
	int							pixel_color;

	pos.x = device->separated_render_curr.x + wft->idx;
	while (pos.x < device->size.x)
	{
		pos.y = device->separated_render_curr.y;
		while (pos.y < device->size.y)
		{
			if (pos.y > device->size.y)
				break ;
			pixel_color = _get_pixel(wft->world, pos);
			put_pixel(device, pos.x, device->size.y - pos.y - 1, pixel_color);
			pos.y += device->separated_render_max.y;
		}
		pos.x += device->separated_render_max.x;
	}
	return (NULL);
}

void	render_image(t_world *world)
{
	pthread_t			thread[THREAD_COUNT];
	t_world_for_thread	data[THREAD_COUNT];
	t_device *const		device = &world->device;
	int					i;

	i = 0;
	while (i < THREAD_COUNT)
	{
		data[i].world = world;
		data[i].idx = i;
		pthread_create(thread + i, NULL, _render_image, data + i);
		i++;
	}
	while (i > 0)
		pthread_join(thread[--i], NULL);
	_update_next_render_idx(device);
}
