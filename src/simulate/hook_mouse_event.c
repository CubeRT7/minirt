/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:10:36 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/12 00:45:14 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	rotate_camera(void *param)
{
	t_world *const		world = param;
	int					xy[2];
	const t_vector3		up = (t_vector3){0, 1, 0};
	t_vector3			front;
	t_vector3			right;

	if (world->camera->obj.rotate_flag == 0)
		return ;
	if (world->camera->obj.rotate_flag == 2)
		world->camera->obj.rotate_flag = 0;
	mlx_get_mouse_pos(world->gui.mlx, &xy[0], &xy[1]);
	front = vector3(world->camera->base.axis.x, 0, world->camera->base.axis.z);
	right = v3_normalize(v3_cross_prod(front, up));
	world->camera->base.axis = v3_rotate_axis(world->camera->base.axis, up,
			(world->camera->obj.cursor_pos.x - xy[0])
			/ world->gui.image->width);
	world->camera->base.axis = v3_rotate_axis(world->camera->base.axis, right,
			(world->camera->obj.cursor_pos.y - xy[1])
			/ world->gui.image->height);
	world->camera->obj.cursor_pos = vector3(xy[0], xy[1], 0);
}

void	hook_mouse_event(
	mouse_key_t button,
	action_t action,
	modifier_key_t mods,
	void *param
)
{
	t_world *const		world = param;
	int					xy[2];

	(void)mods;
	mlx_get_mouse_pos(world->gui.mlx, &xy[0], &xy[1]);
	if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_PRESS)
	{
		world->camera->obj.rotate_flag = 1;
		world->camera->obj.cursor_pos = vector3(xy[0], xy[1], 0);
	}
	else if (button == MLX_MOUSE_BUTTON_RIGHT && action == MLX_RELEASE)
	{
		world->camera->obj.rotate_flag = 2;
		world->camera->obj.cursor_pos = vector3(xy[0], xy[1], 0);
	}
}
