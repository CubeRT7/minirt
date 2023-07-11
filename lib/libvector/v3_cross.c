/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_cross.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:01:13 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 01:51:39 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector3	v3_cross(t_vector3 v1, t_vector3 v2)
{
	const float	x = v1.y * v2.z - v1.z * v2.y;
	const float	y = v1.z * v2.x - v1.x * v2.z;
	const float	z = v1.x * v2.y - v1.y * v2.x;

	return ((t_vector3){x, y, z});
}
