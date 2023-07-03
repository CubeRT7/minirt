/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:04:44 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/03 22:39:24 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	debug_camera(void *param)
{
	struct s_camera *const	c = param;

	if (c == NULL || DEBUG == 0)
		return (EXIT_SUCCESS);
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->raw.coordinate.x, c->raw.coordinate.y, c->raw.coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__,
		c->raw.axis.x, c->raw.axis.y, c->raw.axis.z);
	printf("%s: fov[%f]\n", __func__, c->raw.fov);
	return (EXIT_SUCCESS);
}

t_func	camera(enum e_element_func func)
{
	static const t_func	functions[MAX_ELEMENT_TYPE] = {
	[Init] = init_camera,
	[Hit] = hit_camera,
	[Parse] = parse_camera,
	[Debug] = debug_camera};

	return (functions[func]);
}
