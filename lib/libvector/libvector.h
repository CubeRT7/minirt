/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:14:25 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 01:51:29 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H
# include <math.h>

enum e_v3_preset
{
	V3_ZERO,
	V3_ONE,
	V3_UP,
	V3_DOWN,
	V3_RIGHT,
	V3_LEFT,
	V3_FRONT,
	V3_BACK,
	V3_MAX_PRESET_IDX
};

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

t_vector3	vector3(float x, float y, float z);
t_vector3	v3_add(t_vector3 v1, t_vector3 v2);
t_vector3	v3_sub(t_vector3 v1, t_vector3 v2);
t_vector3	v3_mul(t_vector3 v1, float v2);
t_vector3	v3_normalize(t_vector3 v1);
t_vector3	v3_reverse(t_vector3 v1);
t_vector3	v3_rotate(t_vector3 v, t_vector3 a);
t_vector3	v3_rotate_axis(t_vector3 v, t_vector3 a, float theta);
t_vector3	v3_hadamard(t_vector3 v1, t_vector3 v2);
t_vector3	v3_cross(t_vector3 v1, t_vector3 v2);
float		v3_dot(t_vector3 v1, t_vector3 v2);
float		v3_magnitude(t_vector3 v1);
t_vector3	v3_preset(enum e_v3_preset type);

#endif
