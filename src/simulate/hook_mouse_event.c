/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:10:36 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/12 07:01:46 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	rotate_camera(void *param)
{
	t_world *const		world = param;
	t_camera *const		camera = world->camera;
	int					xy[2];
	t_vector3			v[3];
	float				angle;

	enum e_type {FRONT, RIGHT, NEW};
	if (camera->obj.rotate_flag == 0)
		return ;
	if (camera->obj.rotate_flag == 2)
		camera->obj.rotate_flag = 0;
	mlx_get_mouse_pos(world->gui.mlx, &xy[0], &xy[1]);
	v[FRONT] = v3_normalize(v3_hadamard(camera->base.axis, vector3(1, 0, 1)));
	v[RIGHT] = v3_normalize(v3_cross(v[FRONT], world->axis));
	camera->base.axis = v3_rotate_axis(camera->base.axis, world->axis,
			(camera->obj.cursor_pos.x - xy[0]) / world->gui.image->width);
	v[NEW] = v3_rotate_axis(world->camera->base.axis, v[RIGHT],
			(camera->obj.cursor_pos.y - xy[1]) / world->gui.image->height);
	angle = v3_dot(v3_normalize(v3_cross(v[NEW], world->axis)), v[RIGHT]);
	if (angle > 0)
		camera->base.axis = v[NEW];
	camera->obj.cursor_pos = vector3(xy[0], xy[1], 0);
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
