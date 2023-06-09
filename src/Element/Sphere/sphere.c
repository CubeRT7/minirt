/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 19:25:46 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

void	parse_debug_sphere(void *param)
{
	struct s_sphere *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->raw.coordinate.x, c->raw.coordinate.y, c->raw.coordinate.z);
	printf("%s: diameter[%f]\n", __func__, c->raw.diameter);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
}

int	parse_sphere(void *param, char **argv)
{
	char					*remain;
	struct s_sphere *const	content = param;

	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->type = Sphere;
	if (parse_vector3(&content->raw.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	content->raw.diameter = ft_strtof(argv[1], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&content->raw.rgb, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	parse_debug_sphere(content);
	return (EXIT_SUCCESS);
}

void	*new_sphere(void *param)
{
	t_sphere *const	obj = ft_calloc(1, sizeof(t_sphere));

	if (obj == NULL)
		return (NULL);
	(void)param;
	obj->type = Sphere;
	return (obj);
}

void	destroy_sphere(void *object)
{
	t_sphere *const	obj = object;

	free(obj);
}

int	hit_sphere(void *object, t_ray *ray)
{
	t_sphere *const	obj = object;

	(void)obj;
	(void)ray;
	return (0);
}
