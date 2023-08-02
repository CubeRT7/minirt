/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_front_face.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:58:18 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/05 07:01:26 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_util.h"

inline t_vector3	get_face_normal(t_ray ray, t_vector3 normal)
{
	const int	front_face = v3_dot(ray.direction, normal) < 0;

	if (front_face)
		return (normal);
	return (v3_reverse(normal));
}
