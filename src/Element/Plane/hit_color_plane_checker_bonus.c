/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_plane_checker_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:12:07 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 20:12:16 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "Element/util/element_util_bonus.h"

t_color	hit_color_plane_checker(t_plane *self, t_vector3 uv)
{
	return (get_checkerboard_color(self->base.color, uv.x, uv.y));
}
