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

	world->camera->obj.ratio = (float)world->gui.height / world->gui.width;
	world_iter(world, Update);
	move_camera(world);
	rotate_camera(world);
	return (EXIT_SUCCESS);
}
