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
	t_world *const	world = param;

	world->camera->obj.ratio = (float)world->gui.screen.y / world->gui.screen.x;
	if (world->gui.mouse.action[MOUSE_BUTTON_LEFT] == MOUSE_PRESS)
		world->selected = select_element(world, world->gui.mouse.curr);
	move_camera(world);
	rotate_camera(world);
	transform_objs(world);
	world_iter(world, Update);
	return (EXIT_SUCCESS);
}
