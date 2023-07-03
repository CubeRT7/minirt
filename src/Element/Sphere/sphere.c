/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:04:44 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/03 22:44:13 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

int	debug_sphere(void *param)
{
	struct s_sphere *const	c = param;

	if (c == NULL || DEBUG == 0)
		return (EXIT_SUCCESS);
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->raw.coordinate.x, c->raw.coordinate.y, c->raw.coordinate.z);
	printf("%s: diameter[%f]\n", __func__, c->raw.diameter);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
	return (EXIT_SUCCESS);
}

t_func	sphere(enum e_element_func func)
{
	static const t_func	functions[MAX_ELEMENT_TYPE] = {
	[Init] = init_sphere,
	[Hit] = hit_sphere,
	[Debug] = debug_sphere};

	return (functions[func]);
}
