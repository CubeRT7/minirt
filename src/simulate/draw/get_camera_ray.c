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

#include "draw.h"
#include "Element/Camera/camera.h"

t_ray	get_camera_ray(void *camera, t_screen screen, t_screen pos)
{
	const t_camera	*cam = camera;
	const t_vector3	uv = vector3(
			(float)pos.x / screen.w,
			(float)pos.y / screen.h,
			0);
	t_vector3		v[3];
	float			h_angle;
	float			v_angle;

	enum e_type {DIREC, FRONT, RIGHT};
	v[DIREC] = cam->obj.viewport_lower_left;
	v[DIREC] = v3_add(v[DIREC], v3_mul(cam->obj.viewport_horizontal, uv.x));
	v[DIREC] = v3_add(v[DIREC], v3_mul(cam->obj.viewport_vertical, uv.y));
	v[DIREC] = v3_normalize(v[DIREC]);
	v[FRONT] = v3_normalize(vector3(cam->base.axis.x, 0, cam->base.axis.z));
	v[RIGHT] = v3_normalize(v3_cross(v[FRONT], vector3(0, 1, 0)));
	h_angle = acosf(v3_dot(vector3(0, 0, -1), v[FRONT]) * 0.9999f);
	if (v[FRONT].x >= 0)
		h_angle *= -1;
	v_angle = acosf(v3_dot(v[FRONT], cam->base.axis) * 0.9999f);
	if (cam->base.axis.y < 0)
		v_angle *= -1;
	v[DIREC] = v3_rotate_axis(v[DIREC], vector3(0, 1, 0), h_angle);
	v[DIREC] = v3_rotate_axis(v[DIREC], v[RIGHT], v_angle);
	return ((t_ray){cam->base.position, v[DIREC]});
}
