/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:27:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:31:18 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "metal.h"

static t_vector3	reflect(t_vector3 v, t_vector3 n)
{
	v = v3_normalize(v);
	n = v3_normalize(n);
	return (v3_sub(v, v3_mul(n, 2 * v3_dot_prod(v, n))));
}

int	metal_scatter(t_ray *ray, t_hit *hit, t_color *color)
{
	const t_vector3	reflected = reflect(ray->direction, hit->normal);

	*ray = (t_ray){hit->p, reflected};
	*color = (t_color){1, 1, 1};
	return (v3_dot_prod(ray->direction, hit->normal) > 0);
}
