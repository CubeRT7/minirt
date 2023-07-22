/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:00:18 by yonshin           #+#    #+#             */
/*   Updated: 2023/06/09 16:00:19 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector3	v3_normalize(t_vector3 v1)
{
	const double	mag = v3_magnitude(v1);

	if (mag == 0)
		return ((t_vector3){0, 0, 0});
	return (v3_mul(v1, 1 / mag));
}
