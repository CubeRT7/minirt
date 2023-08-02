/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_sphere_checker_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:25:42 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 20:16:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "Element/util/element_util_bonus.h"
#define DENSITY 4

t_color	hit_color_sphere_checker(t_sphere *self, t_vector3 uv)
{
	const t_vector3	fixed_uv = v3_mul(uv, DENSITY);

	return (get_checkerboard_color(self->base.color, fixed_uv.x, fixed_uv.y));
}
