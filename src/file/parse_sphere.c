/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/07 05:52:14 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Element/Sphere/sphere.h"

int	parse_sphere(void *param, char **argv)
{
	char					*remain;
	struct s_sphere *const	content = param;

	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->base.type = Sphere;
	if (parse_vector3(&content->raw.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	content->raw.diameter = ft_strtof(argv[1], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&content->raw.rgb, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	debug_sphere(content);
	return (EXIT_SUCCESS);
}
