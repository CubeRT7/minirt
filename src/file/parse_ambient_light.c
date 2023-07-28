/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 14:03:35 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_private.h"
#include "../Element/AmbientLight/ambient_light.h"

static int	_debug_ambient_light(void *param)
{
	struct s_ambient_light *const	c = param;

	if (c == NULL || DEBUG == 0)
		return (EXIT_SUCCESS);
	printf("%s: ratio[%f]\n", __func__, c->raw.ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
	return (EXIT_SUCCESS);
}

int	parse_ambient_light(void *param, char **argv)
{
	char							*remain;
	struct s_ambient_light *const	content = param;

	if (!argv || !argv[0] || !argv[1])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->base.type = AmbientLight;
	content->raw.ratio = ft_strtof(argv[0], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&content->raw.rgb, argv[1]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!(0.0 <= content->raw.ratio && content->raw.ratio <= 1.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	_debug_ambient_light(content);
	return (EXIT_SUCCESS);
}
