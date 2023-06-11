/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:28:51 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:29:14 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lambertian.h"

int	lambertian_scatter(t_ray *ray, t_hit *hit, t_color *color)
{
	const t_vector3	random = (t_vector3){
		((double)rand() / RAND_MAX) - 0.5,
		((double)rand() / RAND_MAX) - 0.5,
		((double)rand() / RAND_MAX) - 0.5
	};
	t_vector3	direction = v3_add(v3_normalize(hit->normal), v3_normalize(random));

	(void)ray;
	if (v3_magnitude(direction) < 0.001)
		direction = v3_reverse(direction);
	direction = v3_normalize(direction);
	*ray = (t_ray){hit->p, direction};
	*color = (t_color){0.3, 0.5, 1};
	return (1);
}
