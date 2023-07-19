/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera_ray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:10:35 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 07:18:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate_util.h"
#include "Element/Camera/camera.h"

static float	_angle(t_vector3 axis, t_vector3 v, int minus)
{
	const float	angle = acosf(v3_dot(axis, v) * 0.9999f);

	if (minus)
		return (-angle);
	return (angle);
}

t_ray	get_camera_ray(
	t_camera *cam,
	t_vector3 screen,
	t_vector3 pos,
	t_vector3 delta)
{
	t_vector3	uv;
	t_vector3	v[3];
	float		h_angle;
	float		v_angle;

	enum e_type {DIREC, FRONT, RIGHT};
	uv.x = (pos.x + delta.x) / screen.x;
	uv.y = (pos.y + delta.y) / screen.y;
	v[DIREC] = cam->obj.viewport_lower_left;
	v[DIREC] = v3_add(v[DIREC], v3_mul(cam->obj.viewport_horizontal, uv.x));
	v[DIREC] = v3_add(v[DIREC], v3_mul(cam->obj.viewport_vertical, uv.y));
	v[DIREC] = v3_normalize(v[DIREC]);
	v[FRONT] = v3_normalize(vector3(cam->base.axis.x, 0, cam->base.axis.z));
	v[RIGHT] = v3_normalize(v3_cross(v[FRONT], v3_preset(V3_UP)));
	h_angle = _angle(v3_preset(V3_FRONT), v[FRONT], v[FRONT].x >= 0);
	v_angle = _angle(v[FRONT], cam->base.axis, cam->base.axis.y < 0);
	v[DIREC] = v3_rotate_axis(v[DIREC], v3_preset(V3_UP), h_angle);
	v[DIREC] = v3_rotate_axis(v[DIREC], v[RIGHT], v_angle);
	return ((t_ray){cam->base.position, v[DIREC]});
}
