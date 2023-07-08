/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:10:36 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/08 22:00:00 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	rotate_camera(void *param)
{
	t_world *const	world = param;
	const float		delta = world->gui.mlx->delta_time;
	t_vector3		tmp[2];
	int				xy[2];

	if (world->camera->obj.rotate_flag == 0)
		return ;
	if (world->camera->obj.rotate_flag == 2)
		world->camera->obj.rotate_flag = 0;
	mlx_get_mouse_pos(world->gui.mlx, &xy[0], &xy[1]);
	tmp[0] = v3_normalize(v3_sub(vector3(xy[0], xy[1], 0),
				vector3(world->camera->obj.cursor_xy[0],
					world->camera->obj.cursor_xy[1], 0)));
	tmp[1] = v3_cross_prod(tmp[0], world->camera->obj.axis);
	world->camera->obj.axis = v3_rotate_axis(
			world->camera->obj.axis, tmp[1],
			world->camera->obj.fov_radian * delta);
	world->camera->obj.axis = v3_normalize(world->camera->obj.axis);
	world->camera->obj.cursor_xy[0] = xy[0];
	world->camera->obj.cursor_xy[1] = xy[1];
}

void	hook_mouse_event(
	mouse_key_t button,
	action_t action,
	modifier_key_t mods,
	void *param
)
{
	t_world *const		world = param;

	(void)mods;
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
	{
		world->camera->obj.rotate_flag = 1;
		mlx_get_mouse_pos(world->gui.mlx,
			&world->camera->obj.cursor_xy[0],
			&world->camera->obj.cursor_xy[1]);
	}
	else if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_RELEASE)
	{
		world->camera->obj.rotate_flag = 2;
		mlx_get_mouse_pos(world->gui.mlx,
			&world->camera->obj.cursor_xy[0],
			&world->camera->obj.cursor_xy[1]);
	}
}
