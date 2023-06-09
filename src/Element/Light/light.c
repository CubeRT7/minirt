/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 23:27:25 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

void	parse_debug_light(void *param)
{
	struct s_light *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->raw.coordinate.x, c->raw.coordinate.y, c->raw.coordinate.z);
	printf("%s: ratio[%f]\n", __func__, c->raw.ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
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
	parse_debug_light(content);
	return (EXIT_SUCCESS);
}
