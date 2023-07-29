/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_plane_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 12:20:42 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"
#include "Element/util/element_util_bonus.h"
#include "mlx.h"

t_color	hit_color_plane_checker(t_plane *self, t_vector3 world_point);
t_color	hit_color_plane_bumpmap(t_plane *s, t_vector3 point, t_vector3 *normal);

int	hit_color_plane(t_plane *self, t_hit *rec)
{
	rec->color = hit_color_plane_checker(self, rec->p);
	if (1)
		rec->color = hit_color_plane_bumpmap(self, rec->p, &(rec->normal));
	return (EXIT_SUCCESS);
}
