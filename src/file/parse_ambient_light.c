/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 20:59:47 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_private.h"
#include "../Element/AmbientLight/ambient_light.h"

static void	_debug(struct s_parse_dto dto)
{
	if (DEBUG == 0)
		return ;
	printf("%s: ratio[%f]\n", __func__, dto.ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		dto.rgb.r, dto.rgb.g, dto.rgb.b);
}

static void	_init(void *param, struct s_parse_dto dto)
{
	struct s_ambient_light *const	self = param;

	self->base.type = AmbientLight;
	self->base.type_name = "AmbientLight";
	self->base.color = rgb_to_color(dto.rgb);
	self->ratio = dto.ratio;
}

int	parse_ambient_light(void *param, char **argv)
{
	struct s_parse_dto	dto;

	if (size_should_be(argv, 2))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_double(&dto.ratio, argv[0]))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&dto.rgb, argv[1]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!(0.0 <= dto.ratio && dto.ratio <= 1.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	_debug(dto);
	_init(param, dto);
	return (EXIT_SUCCESS);
}
