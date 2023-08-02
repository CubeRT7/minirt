/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 09:20:47 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/05 09:20:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_util.h"

inline t_point	get_ray_point(const t_ray *ray, double t)
{
	return (v3_add(v3_mul(ray->direction, t), ray->origin));
}
