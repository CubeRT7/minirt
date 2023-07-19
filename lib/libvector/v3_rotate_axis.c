/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_rotate_axis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:57:42 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:37:36 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector3	v3_rotate_axis(t_vector3 v, t_vector3 a, double theta)
{
	const double	cth = cos(theta);
	const double	sth = sin(theta);
	const double	dot = v3_dot(a, v);
	const t_vector3	crs = v3_cross(a, v);
	t_vector3		res;

	res = v3_mul(v, cth);
	res = v3_add(res, v3_mul(crs, sth));
	res = v3_add(res, v3_mul(a, dot * (1 - cth)));
	return (res);
}
