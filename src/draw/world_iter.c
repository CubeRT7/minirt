/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 07:06:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/31 17:22:06 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

extern int	init_ambient_light(void *self);
extern int	init_camera(void *self);

void	world_iter(t_world *world, enum e_element_func e)
{
	if (e == Init)
	{
		init_ambient_light(world->ambient_light);
		init_camera(world->camera);
		element_iter(world->lights, e);
		element_iter(world->objs, e);
		return ;
	}
	if (world->ambient_light->base.func[e])
		world->ambient_light->base.func[e](world->ambient_light);
	if (world->camera->base.func[e])
		world->camera->base.func[e](world->camera);
	element_iter(world->lights, e);
	element_iter(world->objs, e);
}
