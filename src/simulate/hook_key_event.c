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
	t_camera *const	camera = world->camera;
	const float		delta = world->gui.mlx->delta_time;
	const t_vector3	front = vector3(camera->base.axis.x, 0, camera->base.axis.z);
	const t_vector3	right = v3_cross_prod(front, vector3(0, 1, 0));
	const t_vector3	direction[3] = {
		v3_mul(front, delta), v3_mul(right, delta), vector3(0, delta, 0)};

	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_W))
		camera->base.position = v3_add(camera->base.position, direction[0]);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_S))
		camera->base.position = v3_sub(camera->base.position, direction[0]);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_A))
		camera->base.position = v3_sub(camera->base.position, direction[1]);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_D))
		camera->base.position = v3_add(camera->base.position, direction[1]);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_SPACE))
		camera->base.position = v3_add(camera->base.position, direction[2]);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_LEFT_CONTROL))
		camera->base.position = v3_sub(camera->base.position, direction[2]);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_R))
		camera->base.axis = v3_rotate_axis(camera->base.axis, right, delta);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_F))
		camera->base.axis = v3_rotate_axis(camera->base.axis, right, -delta);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_Q))
		camera->base.axis = v3_rotate_axis(camera->base.axis, vector3(0, 1, 0), delta);
	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_E))
		camera->base.axis = v3_rotate_axis(camera->base.axis, vector3(0, 1, 0), -delta);
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
