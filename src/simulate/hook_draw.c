/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 08:32:49 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "simulate/util/simulate_util.h"
#include "simulate/draw/draw.h"

void	hook_draw(void *param)
{
	t_world *const		world = param;
	mlx_image_t *const	img = world->gui.image;
	t_screen			screen;
	t_screen			pos;
	t_ray				ray;

	screen.w = img->width;
	screen.h = img->height;
	pos.x = 0;
	while (pos.x < screen.w)
	{
		pos.y = 0;
		while (pos.y < screen.h)
		{
			ray = get_camera_ray(world->camera, screen, pos);
			mlx_put_pixel(img, pos.x, screen.h - pos.y - 1,
				color_to_pixel(ray_color(&ray,
						world->objs,
						world->ambient_light,
						world->lights)));
			++pos.y;
		}
		++pos.x;
	}
}
