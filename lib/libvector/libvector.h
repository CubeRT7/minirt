/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:14:25 by yonshin           #+#    #+#             */
/*   Updated: 2023/06/09 16:14:26 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H
# include <math.h>

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
t_vector3	v3_cross_prod(t_vector3 v1, t_vector3 v2);
float		v3_dot_prod(t_vector3 v1, t_vector3 v2);
float		v3_magnitude(t_vector3 v1);

#endif
