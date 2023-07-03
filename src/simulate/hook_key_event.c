/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:03:45 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "Element/Sphere/sphere.h"

void	hook_key_event(void *param)
{
	t_world *const	world = param;
	const float		delta = world->gui.mlx->delta_time;

	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(world->gui.mlx);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_LEFT_BRACKET))
	{
		world->camera->obj.fov_radian -= delta;
		if (world->camera->obj.fov_radian <= 0)
			world->camera->obj.fov_radian = 0;
	}
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_RIGHT_BRACKET))
	{
		world->camera->obj.fov_radian += delta;
		if (world->camera->obj.fov_radian >= M_PI)
			world->camera->obj.fov_radian = M_PI;
	}
}
