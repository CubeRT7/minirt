/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/30 01:32:54 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_private.h"
#include "../Element/Sphere/sphere.h"

static void	_debug(struct s_parse_dto dto)
{
	if (DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		dto.coordinate.x, dto.coordinate.y, dto.coordinate.z);
	printf("%s: diameter[%f]\n", __func__, dto.diameter);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		dto.rgb.r, dto.rgb.g, dto.rgb.b);
}

static void	_init(void *param, struct s_parse_dto dto)
{
	struct s_sphere *const	self = param;

	self->base.type = Sphere;
	self->base.type_name = "Sphere";
	self->base.position = dto.coordinate;
	self->base.front = v3_preset(V3_FRONT);
	self->base.up = v3_preset(V3_UP);
	self->base.right = v3_preset(V3_RIGHT);
	self->base.color = rgb_to_color(dto.rgb);
	self->radius = dto.diameter * 0.5;
	self->base.mapid = (int)dto.mapid;
}

int	parse_sphere(void *param, char **argv)
{
	struct s_parse_dto	dto;

	if (size_range_in(argv, 3, 4))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_vector3(&dto.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_double(&dto.diameter, argv[1]))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&dto.rgb, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (argv[3] != NULL && parse_double(&dto.mapid, argv[3]))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (argv[3] == NULL)
		dto.mapid = 0;
	_debug(dto);
	_init(param, dto);
	return (EXIT_SUCCESS);
}
