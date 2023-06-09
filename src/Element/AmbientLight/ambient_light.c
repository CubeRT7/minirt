/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 19:25:16 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient_light.h"

void	parse_debug_ambient_light(void *param)
{
	struct s_ambient_light *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: ratio[%f]\n", __func__, c->raw.ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		c->raw.rgb.r, c->raw.rgb.g, c->raw.rgb.b);
}

int	parse_ambient_light(void *param, char **argv)
{
	char							*remain;
	struct s_ambient_light *const	content = param;

	if (!argv || !argv[0] || !argv[1])
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	content->type = AmbientLight;
	content->raw.ratio = ft_strtof(argv[0], &remain);
	if (errno || (*remain != '\0' && ft_strchr("\r\n", *remain) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&content->raw.rgb, argv[1]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!(0.0 <= content->raw.ratio && content->raw.ratio <= 1.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	parse_debug_ambient_light(content);
	return (EXIT_SUCCESS);
}

void	*new_ambient_light(void *param)
{
	t_ambient_light *const	obj = ft_calloc(1, sizeof(t_ambient_light));

	if (obj == NULL)
		return (NULL);
	(void)param;
	obj->type = AmbientLight;
	return (obj);
}

void	destroy_ambient_light(void *object)
{
	t_ambient_light *const	obj = object;

	free(obj);
}

int	hit_ambient_light(void *object, t_ray *ray)
{
	t_ambient_light *const	obj = object;

	(void)obj;
	(void)ray;
	return (0);
}
