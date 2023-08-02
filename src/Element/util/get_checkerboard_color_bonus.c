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
	const int	reverse = (int)(_fix(u) * 2) + (int)(_fix(v) * 2);
	t_vector3	newcolor;

	newcolor = v3_add(color, vector3(0.1, 0.1, 0.1));
	if (newcolor.x > 1)
		newcolor.x = color.x - 0.1;
	if (newcolor.y > 1)
		newcolor.y = color.y - 0.1;
	if (newcolor.z > 1)
		newcolor.z = color.z - 0.1;
	if (reverse % 2)
		return (newcolor);
	return (color);
}
