/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/31 04:21:23 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

extern int	hit_sphere(t_sphere *self, t_ray *r, t_range ra, t_hit *h);
extern int	hit_color_sphere(t_sphere *self, t_hit *record);
extern int	transform_sphere(
				t_sphere *self,
				const t_element *camera,
				enum e_transform_type type,
				t_vector3 delta);

int	init_sphere(t_sphere *self)
{
	self->base.func[Hit] = hit_sphere;
	self->base.func[HitColor] = hit_color_sphere;
	self->base.func[Transform] = transform_sphere;
	return (EXIT_SUCCESS);
}
