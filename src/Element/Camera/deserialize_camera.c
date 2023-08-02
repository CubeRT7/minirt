/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:36:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 15:55:49 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/parse_util.h"
#include "../Element/Camera/camera.h"

static void	_debug(struct s_parse_dto dto)
{
	if (DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		dto.coordinate.x, dto.coordinate.y, dto.coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__,
		dto.axis.x, dto.axis.y, dto.axis.z);
	printf("%s: fov[%f]\n", __func__, dto.fov);
}

static void	_init(void *param, struct s_parse_dto dto)
{
	struct s_camera *const	self = param;

	self->base.type = Camera;
	self->base.type_name = "Camera";
	self->base.position = dto.coordinate;
	self->base.front = v3_normalize(dto.axis);
	self->base.up = v3_preset(V3_UP);
	self->base.right = v3_cross(self->base.front, self->base.up);
	if (close_to_zero(v3_magnitude(self->base.right)))
		self->base.right = v3_preset(V3_RIGHT);
	self->base.up = v3_cross(self->base.right, self->base.front);
	self->fov_radian = dto.fov / 180 * M_PI;
}

int	parse_camera(void *param, char **argv)
{
	struct s_parse_dto	dto;

	ft_bzero(&dto, sizeof(struct s_parse_dto));
	if (size_should_be(argv, 3))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_vector3(&dto.coordinate, argv[0], AllScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_vector3(&dto.axis, argv[1], UnitScope))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (parse_double(&dto.fov, argv[2]))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (!(0.0 <= dto.fov && dto.fov <= 180.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	_debug(dto);
	_init(param, dto);
	return (EXIT_SUCCESS);
}

t_element	*deserialize_camera(const char *line)
{
	int				ret;
	char			**cols;
	t_camera *const	self = ft_calloc(1, sizeof(t_camera));

	if (self == NULL)
		return (NULL);
	cols = ft_split(line, ' ');
	if (cols == NULL)
	{
		free(self);
		return (NULL);
	}
	ret = parse_camera(self, cols);
	ft_strarr_free(cols);
	if (ret == EXIT_FAILURE)
	{
		free(self);
		return (NULL);
	}
	return ((t_element *)self);
}
