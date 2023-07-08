/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:10:36 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/09 06:40:35 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	rotate_camera(void *param)
{
	t_world *const		world = param;
	int					xy[2];
	t_vector3			front;
	t_vector3			right;
	t_vector3			move;

	if (world->camera->obj.rotate_flag == 0)
		return ;
	if (world->camera->obj.rotate_flag == 2)
		world->camera->obj.rotate_flag = 0;
	mlx_get_mouse_pos(world->gui.mlx, &xy[0], &xy[1]);
	move = v3_sub(world->camera->obj.cursor_pos, vector3(xy[0], xy[1], 0));
	front = world->camera->obj.axis;
	right = v3_normalize(v3_cross_prod(front, world->camera->obj.up));
	world->camera->obj.axis = v3_rotate_axis(world->camera->obj.axis,
			world->camera->obj.up,
			move.x / world->gui.image->width);
	world->camera->obj.axis = v3_rotate_axis(world->camera->obj.axis,
			right,
			move.y / world->gui.image->height);
	world->camera->obj.up = v3_rotate_axis(world->camera->obj.up,
			right, move.y / world->gui.image->height);
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
