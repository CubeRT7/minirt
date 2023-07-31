/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/31 16:56:26 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_private.h"
#include "../Element/Light/light.h"

static void	_debug(struct s_parse_dto dto)
{
	if (DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		dto.coordinate.x, dto.coordinate.y, dto.coordinate.z);
	printf("%s: ratio[%f]\n", __func__, dto.ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		dto.rgb.r, dto.rgb.g, dto.rgb.b);
}

static void	_init(void *param, struct s_parse_dto dto)
{
	struct s_light *const	self = param;

	self->base.type = Light;
	self->base.type_name = "Light";
	self->base.position = dto.coordinate;
	self->base.front = v3_normalize(dto.axis);
	self->base.color = rgb_to_color(dto.rgb);
	self->ratio = dto.ratio;
}

int	parse_light(void *param, char **argv)
{
	struct s_parse_dto	dto;

	ft_bzero(&dto, sizeof(struct s_parse_dto));
	if (size_range_in(argv, 2, 3))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_vector3(&dto.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_double(&dto.ratio, argv[1]))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (!(0.0 <= dto.ratio && dto.ratio <= 1.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (argv[2] && parse_rgb(&dto.rgb, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (argv[2] == NULL)
		dto.rgb = (t_rgb){255, 255, 255};
	_debug(dto);
	_init(param, dto);
	return (EXIT_SUCCESS);
}
