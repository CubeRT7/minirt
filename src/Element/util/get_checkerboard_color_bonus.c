/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_checkerboard_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 08:43:53 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/23 08:43:54 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_util_bonus.h"

static double	_fix(double d)
{
	if (d < 0)
		return (d - ((int)d - 1) + 0.00000000001);
	return (d - (int)d);
}

t_color	get_checkerboard_color(t_color color, double u, double v)
{
	const t_vector3	newcolor = v3_add(color, vector3(0.1, 0.1, 0.1));
	const int		reverse = (int)(_fix(u) * 2) + (int)(_fix(v) * 2);

	if (reverse % 2)
		return (vector3(_fix(newcolor.x), _fix(newcolor.y), _fix(newcolor.z)));
	return (color);
}
