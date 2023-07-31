/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_cone_checker_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:37:12 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 20:48:12 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"
#include "Element/util/element_util_bonus.h"
#define DENSITY 4

t_color	hit_color_cone_checker(t_cone *self, t_vector3 uv)
{
	const t_vector3	fixed_uv = v3_mul(uv, DENSITY);

	return (get_checkerboard_color(self->base.color, fixed_uv.x, fixed_uv.y));
}
