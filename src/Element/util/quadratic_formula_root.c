/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_formula_root.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 05:48:01 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/06 05:48:02 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_util.h"

inline int	quadratic_formula_root(t_abc abc, t_range range, float *x)
{
	const float	discriminant = abc.b * abc.b - abc.a * abc.c;
	float		sqrtd;

	if (discriminant < 0)
		return (NO_VALUE);
	sqrtd = sqrt(discriminant);
	*x = (-abc.b - sqrtd) / abc.a;
	if (range_not_in(*x, range))
	{
		*x = (-abc.b + sqrtd) / abc.a;
		if (range_not_in(*x, range))
			return (NO_VALUE);
	}
	return (HAS_VALUE);
}
