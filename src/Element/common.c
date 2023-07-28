/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 14:32:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "Element/AmbientLight/ambient_light.h"
#include "Element/Camera/camera.h"
#include "Element/Light/light.h"
#include "Element/Plane/plane.h"
#include "Element/Sphere/sphere.h"
#include "Element/Cylinder/cylinder.h"

void	init_element(void *elem)
{
	const t_element	*self = elem;

	if (self->type == AmbientLight)
		init_ambient_light(elem);
	if (self->type == Camera)
		init_camera(elem);
	if (self->type == Light)
		init_light(elem);
	if (self->type == Plane)
		init_plane(elem);
	if (self->type == Sphere)
		init_sphere(elem);
	if (self->type == Cylinder)
		init_cylinder(elem);
}

void	element_iter(t_list *list, enum e_element_func e)
{
	if (e == Init)
	{
		while (list)
		{
			init_element(list->content);
			list = list->next;
		}
		return ;
	}
	while (list)
	{
		if (((t_element *)(list->content))->func[e])
			((t_element *)(list->content))->func[e](list->content);
		list = list->next;
	}
}
