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

static void	move_camera(t_world *world)
{
	t_element *const	camera = &(world->camera->base);
	const float			delta = world->gui.mlx->delta_time;
	t_vector3			v[3];

	enum e_type {FRONT, RIGHT, NEW};
	v[FRONT] = v3_normalize(v3_hadamard(camera->axis, vector3(1, 0, 1)));
	v[RIGHT] = v3_cross(v[FRONT], WORLD_AXIS);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_W))
		camera->position = v3_add(camera->position, v3_mul(v[FRONT], delta));
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_S))
		camera->position = v3_sub(camera->position, v3_mul(v[FRONT], delta));
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_A))
		camera->position = v3_sub(camera->position, v3_mul(v[RIGHT], delta));
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_D))
		camera->position = v3_add(camera->position, v3_mul(v[RIGHT], delta));
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_SPACE))
		camera->position = v3_add(camera->position, v3_mul(WORLD_AXIS, delta));
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_LEFT_CONTROL))
		camera->position = v3_sub(camera->position, v3_mul(WORLD_AXIS, delta));
}

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
	move_camera(world);
}
