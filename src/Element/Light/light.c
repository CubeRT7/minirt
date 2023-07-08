/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:04:44 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/03 22:44:01 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

int	debug_light(void *param)
{
	struct s_light *const	c = param;

	if (c == NULL || DEBUG == 0)
		return (EXIT_SUCCESS);
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->base.position.x, c->base.position.y, c->base.position.z);
	printf("%s: ratio[%f]\n", __func__, c->raw.ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
	return (EXIT_SUCCESS);
}

t_func	light(enum e_element_func func)
{
	static const t_func	functions[MAX_ELEMENT_TYPE] = {
	[Init] = init_light,
	[Debug] = debug_light};

	return (functions[func]);
}
