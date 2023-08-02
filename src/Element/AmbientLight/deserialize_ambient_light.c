/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize_ambient_light.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 15:52:08 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/parse_util.h"
#include "../Element/AmbientLight/ambient_light.h"

static void	_debug(struct s_parse_dto dto)
{
	if (DEBUG == 0)
		return ;
	printf("%s: ratio[%f]\n", __func__, dto.ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__,
		dto.rgb.r, dto.rgb.g, dto.rgb.b);
}

static void	_init(t_ambient_light *self, struct s_parse_dto dto)
{
	self->base.type = AmbientLight;
	self->base.type_name = "AmbientLight";
	self->base.color = rgb_to_color(dto.rgb);
	self->ratio = dto.ratio;
}

int	parse_ambient_light(t_ambient_light *self, char **argv)
{
	struct s_parse_dto	dto;

	ft_bzero(&dto, sizeof(struct s_parse_dto));
	if (size_should_be(argv, 2))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_double(&dto.ratio, argv[0]))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (parse_rgb(&dto.rgb, argv[1]))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!(0.0 <= dto.ratio && dto.ratio <= 1.0))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	_debug(dto);
	_init(self, dto);
	return (EXIT_SUCCESS);
}

t_element	*deserialize_ambient_light(const char *line)
{
	int						ret;
	char					**cols;
	t_ambient_light *const	self = ft_calloc(1, sizeof(t_ambient_light));

	if (self == NULL)
		return (NULL);
	cols = ft_split(line, ' ');
	if (cols == NULL)
	{
		free(self);
		return (NULL);
	}
	ret = parse_ambient_light(self, cols);
	ft_strarr_free(cols);
	if (ret == EXIT_FAILURE)
	{
		free(self);
		return (NULL);
	}
	return ((t_element *)self);
}
