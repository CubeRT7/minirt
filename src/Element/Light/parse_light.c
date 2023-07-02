/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/10 00:49:00 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

int	debug_light(void *param)
{
	struct s_light *const	c = param;

	if (c == NULL || DEBUG == 0)
		return (EXIT_SUCCESS);
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->obj.position.x, c->obj.position.y, c->obj.position.z);
	printf("%s: ratio[%f]\n", __func__, c->raw.ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
	return (EXIT_SUCCESS);
}

int	parse_light(void *param, char **argv)
{
	char					*remain;
	struct s_light *const	content = param;

	if (!argv || !argv[0] || !argv[1])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->type = Light;
	if (parse_vector3(&content->raw.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	content->raw.ratio = ft_strtof(argv[1], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (!(0.0 <= content->raw.ratio && content->raw.ratio <= 1.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (argv[2] && parse_rgb(&content->raw.rgb, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	debug_light(content);
	return (EXIT_SUCCESS);
}
