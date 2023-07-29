/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_sphere_bumpmap_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:25:39 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 12:55:09 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "Element/util/element_util_bonus.h"

t_color	hit_color_sphere_bumpmap(
    t_sphere *self,
    t_vector3 world_point,
    t_vector3 *normal)
{
	(void)self;
	(void)world_point;
	(void)normal;
	return (self->base.color);
}
