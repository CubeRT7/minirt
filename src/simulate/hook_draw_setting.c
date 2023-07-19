/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:15:47 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/15 12:56:02 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "simulate/util/simulate_util.h"

int	hook_draw_setting(void *param)
{
	t_world *const			world = param;
	t_gui_setting *const	gui = &(world->gui);
	const t_vector3			point_in_world = vector3(
			gui->mouse.curr.x,
			gui->screen.y - gui->mouse.curr.y,
			0);

	world->camera->obj.ratio = (double)gui->screen.y / gui->screen.x;
	if (gui->mouse.action[MOUSE_BUTTON_LEFT] == MOUSE_PRESS)
		world->selected = select_element(world, point_in_world);
	move_camera(world);
	rotate_camera(world);
	transform_objs(world);
	world_iter(world, Update);
	return (EXIT_SUCCESS);
}
