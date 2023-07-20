/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:15:47 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 09:09:01 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "simulate/util/simulate_util.h"

int	hook_draw_setting(void *param)
{
	t_world *const		world = param;
	t_viewport *const	viewport = &world->viewport;
	const t_vector3		point_in_world = vector3(
			viewport->mouse.curr.x,
			viewport->size.y - viewport->mouse.curr.y,
			0);

	world->camera->obj.ratio = (double)viewport->size.y / viewport->size.x;
	if (viewport->mouse.action[MOUSE_BUTTON_LEFT] == MOUSE_PRESS)
		world->selected = select_element(world, point_in_world);
	if (viewport->keyboard[KEYBOARD_RETURN] && world->lights)
		world->selected = (t_element *)(world->lights->content);
	move_camera(world);
	rotate_camera(world);
	transform_objs(world);
	world_iter(world, Update);
	return (EXIT_SUCCESS);
}
