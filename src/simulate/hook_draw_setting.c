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

t_element	*_select_element(t_world *world, int x, int y)
{
	t_screen	screen;
	t_screen	pos;
	t_ray		ray;
	t_hit		record;

	screen.w = world->gui.width;
	screen.h = world->gui.height;
	pos.x = x;
	pos.y = screen.h - y;
	ray = get_camera_ray(world->camera, screen, pos);
	if (hit(world->objs, &ray, (t_range){DELTA, BIGVALUE}, &record))
		return (record.elem);
	return (NULL);
}

int	hook_draw_setting(void *param)
{
	t_world *const	world = param;

	world->camera->obj.ratio = (float)world->gui.height / world->gui.width;
	if (world->gui.mouse.action[MOUSE_BUTTON_LEFT] == MOUSE_PRESS)
		world->selected = _select_element(world, world->gui.mouse.curr.x, world->gui.mouse.curr.y);
	world_iter(world, Update);
	move_camera(world);
	rotate_camera(world);
	return (EXIT_SUCCESS);
}
