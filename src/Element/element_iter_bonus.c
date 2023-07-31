/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/31 04:23:38 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

extern int	init_ambient_light(void *self);
extern int	init_light(void *self);
extern int	init_camera(void *self);
extern int	init_plane(void *self);
extern int	init_sphere(void *self);
extern int	init_cylinder(void *self);
extern int	init_cone(void *self);

static void	_init_element(t_element *self)
{
	if (self->type == AmbientLight)
		init_ambient_light(self);
	if (self->type == Camera)
		init_camera(self);
	if (self->type == Light)
		init_light(self);
	if (self->type == Plane)
		init_plane(self);
	if (self->type == Sphere)
		init_sphere(self);
	if (self->type == Cylinder)
		init_cylinder(self);
	if (self->type == Cone)
		init_cone(self);
}

void	element_iter(t_list *list, enum e_element_func e)
{
	if (e == Init)
	{
		while (list)
		{
			_init_element(list->content);
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
