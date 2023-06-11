/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 01:57:42 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:37:36 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

static void	mul(const t_vector3 *m1, const t_vector3 *m2, t_vector3 *result)
{
	result[0].x = m1[0].x * m2[0].x + m1[0].y * m2[1].x + m1[0].z * m2[2].x;
	result[0].y = m1[0].x * m2[0].y + m1[0].y * m2[1].y + m1[0].z * m2[2].y;
	result[0].z = m1[0].x * m2[0].z + m1[0].y * m2[1].z + m1[0].z * m2[2].z;
	result[1].x = m1[1].x * m2[0].x + m1[1].y * m2[1].x + m1[1].z * m2[2].x;
	result[1].y = m1[1].x * m2[0].y + m1[1].y * m2[1].y + m1[1].z * m2[2].y;
	result[1].z = m1[1].x * m2[0].z + m1[1].y * m2[1].z + m1[1].z * m2[2].z;
	result[2].x = m1[2].x * m2[0].x + m1[2].y * m2[1].x + m1[2].z * m2[2].x;
	result[2].y = m1[2].x * m2[0].y + m1[2].y * m2[1].y + m1[2].z * m2[2].y;
	result[2].z = m1[2].x * m2[0].z + m1[2].y * m2[1].z + m1[2].z * m2[2].z;
}

t_vector3	v3_rotate(t_vector3 v, t_vector3 a)
{
	const t_vector3	angle_x[3] = {
		vector3(1, 0, 0),
		vector3(0, cosf(a.x), -sinf(a.x)),
		vector3(0, sinf(a.x), cosf(a.x))};
	const t_vector3	angle_y[3] = {
		vector3(cosf(a.y), 0, sinf(a.y)),
		vector3(0, 1, 0),
		vector3(-sinf(a.y), 0, cosf(a.y))};
	const t_vector3	angle_z[3] = {
		vector3(cosf(a.z), -sinf(a.z), 0),
		vector3(sinf(a.z), cosf(a.z), 0),
		vector3(0, 0, 1)};
	t_vector3		mul_xy[3];
	t_vector3		rotate[3];

	mul(angle_x, angle_y, mul_xy);
	mul(mul_xy, angle_z, rotate);
	return ((t_vector3){
		rotate[0].x * v.x + rotate[0].y * v.y + rotate[0].z * v.z,
		rotate[1].x * v.x + rotate[1].y * v.y + rotate[1].z * v.z,
		rotate[2].x * v.x + rotate[2].y * v.y + rotate[2].z * v.z
	});
}
