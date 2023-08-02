/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 16:00:28 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/parse_util.h"
#include "../Element/Plane/plane.h"

static void	_debug(struct s_parse_dto dto)
{
	if (DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		dto.coordinate.x, dto.coordinate.y, dto.coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__,
		dto.axis.x, dto.axis.y, dto.axis.z);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		dto.rgb.r, dto.rgb.g, dto.rgb.b);
}

static void	_init(void *param, struct s_parse_dto dto)
{
	struct s_plane *const	self = param;

	self->base.type = Plane;
	self->base.type_name = "Plane";
	self->base.position = dto.coordinate;
	self->base.front = v3_normalize(dto.axis);
	self->base.up = v3_preset(V3_UP);
	self->base.right = v3_cross(self->base.front, self->base.up);
	if (close_to_zero(v3_magnitude(self->base.right)))
		self->base.right = v3_preset(V3_RIGHT);
	self->base.up = v3_cross(self->base.right, self->base.front);
	self->base.color = rgb_to_color(dto.rgb);
}

int	parse_plane(void *param, char **argv)
{
	struct s_parse_dto	dto;

	ft_bzero(&dto, sizeof(struct s_parse_dto));
	if (size_should_be(argv, 3))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_vector3(&dto.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_vector3(&dto.axis, argv[1], UnitScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_rgb(&dto.rgb, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	_debug(dto);
	_init(param, dto);
	return (EXIT_SUCCESS);
}

t_element	*deserialize_plane(const char *line)
{
	int				ret;
	char			**cols;
	t_plane *const	self = ft_calloc(1, sizeof(t_plane));

	if (self == NULL)
		return (NULL);
	cols = ft_split(line, ' ');
	if (cols == NULL)
	{
		free(self);
		return (NULL);
	}
	ret = parse_plane(self, cols);
	ft_strarr_free(cols);
	if (ret == EXIT_FAILURE)
	{
		free(self);
		return (NULL);
	}
	return ((t_element *)self);
}
