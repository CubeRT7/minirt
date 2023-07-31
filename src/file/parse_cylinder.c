/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/31 16:57:42 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_private.h"
#include "../Element/Cylinder/cylinder.h"

static void	_debug(struct s_parse_dto dto)
{
	if (DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		dto.coordinate.x, dto.coordinate.y, dto.coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__,
		dto.axis.x, dto.axis.y, dto.axis.z);
	printf("%s: diameter[%f]\n", __func__, dto.diameter);
	printf("%s: height[%f]\n", __func__, dto.height);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		dto.rgb.r, dto.rgb.g, dto.rgb.b);
}

static void	_init(void *param, struct s_parse_dto dto)
{
	struct s_cylinder *const	self = param;

	self->base.type = Cylinder;
	self->base.type_name = "Cylinder";
	self->base.position = dto.coordinate;
	self->base.color = rgb_to_color(dto.rgb);
	self->base.front = v3_normalize(dto.axis);
	self->base.up = v3_preset(V3_UP);
	self->base.right = v3_cross(self->base.front, self->base.up);
	if (close_to_zero(v3_magnitude(self->base.right)))
		self->base.right = v3_preset(V3_RIGHT);
	self->base.up = v3_cross(self->base.right, self->base.front);
	self->radius = dto.diameter * 0.5;
	self->height = dto.height;
}

int	parse_cylinder(void *param, char **argv)
{
	struct s_parse_dto	dto;

	ft_bzero(&dto, sizeof(struct s_parse_dto));
	if (size_should_be(argv, 5))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_vector3(&dto.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_vector3(&dto.axis, argv[1], UnitScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_double(&dto.diameter, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_double(&dto.height, argv[3]))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&dto.rgb, argv[4]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	_debug(dto);
	_init(param, dto);
	return (EXIT_SUCCESS);
}
