/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_sphere_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 13:00:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "Element/util/element_util_bonus.h"

t_color	hit_color_sphere_checker(t_sphere *self, t_vector3 world_point);
t_color	hit_color_sphere_bumpmap(t_sphere *s, t_vector3 point, t_vector3 *normal);

int	hit_color_sphere(t_sphere *self, t_hit *rec)
{
	rec->color = hit_color_sphere_checker(self, rec->p);
	if (1)
		rec->color = hit_color_sphere_bumpmap(self, rec->p, &(rec->normal));
	return (EXIT_SUCCESS);
}
