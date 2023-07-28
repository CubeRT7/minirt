/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 04:16:02 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 11:02:17 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_element	*select_element(t_world *world, t_vector3 pos)
{
	const t_vector3	size = world->device.size;
	t_ray			ray;
	t_hit			record;

	ray = get_camera_ray(world->camera, size, pos, v3_preset(V3_ZERO));
	if (hit(world->objs, &ray, (t_range){DELTA, BIGVALUE}, &record))
		return (record.elem);
	return (NULL);
}
