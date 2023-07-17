/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 04:16:02 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/16 04:16:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate_util.h"

t_element	*select_element(t_world *world, t_vector3 pos)
{
	const t_vector3	screen = world->gui.screen;
	t_ray			ray;
	t_hit			record;

	ray = get_camera_ray(world->camera, screen, pos);
	if (hit(world->objs, &ray, (t_range){DELTA, BIGVALUE}, &record))
		return (record.elem);
	return (NULL);
}