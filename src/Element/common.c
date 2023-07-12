/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/12 08:36:43 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "Element/AmbientLight/ambient_light.h"
#include "Element/Camera/camera.h"
#include "Element/Light/light.h"
#include "Element/Plane/plane.h"
#include "Element/Sphere/sphere.h"
#include "Element/Cylinder/cylinder.h"

static char	*next_rgb(int *buf, char *curr)
{
	if (curr == NULL || ft_isdigit(curr[0]) == 0)
		return (NULL);
	*buf = ft_atoi(curr);
	if (!(0 <= *buf && *buf <= 255))
		return (NULL);
	while (ft_isdigit(curr[0]))
		++curr;
	if (curr[0] != '\0' && ft_strchr(",\r\n", curr[0]) == NULL)
		return (NULL);
	return (curr);
}

int	parse_rgb(struct s_rgb *rgb, char *curr)
{
	curr = next_rgb(&rgb->r, curr);
	if (curr == NULL || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	curr = next_rgb(&rgb->g, curr + 1);
	if (curr == NULL || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	curr = next_rgb(&rgb->b, curr + 1);
	if (curr == NULL || (curr[0] != '\0' && ft_strchr("\r\n", curr[0]) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	return (EXIT_SUCCESS);
}

int	parse_vector3(t_vector3 *vector, char *curr, float scope)
{
	float	axis_len;

	vector->x = ft_strtof(curr, &curr);
	if (errno || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	vector->y = ft_strtof(curr + 1, &curr);
	if (errno || curr[0] != ',')
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	vector->z = ft_strtof(curr + 1, &curr);
	if (errno || (curr[0] != '\0' && ft_strchr("\r\n", curr[0]) == NULL))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (scope == AllScope)
		return (EXIT_SUCCESS);
	if (!((-1.0 <= vector->x && vector->x <= 1.0)
			&& (-1.0 <= vector->y && vector->y <= 1.0)
			&& (-1.0 <= vector->z && vector->z <= 1.0)))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	axis_len = v3_magnitude(*vector);
	if (!(0.9999f < axis_len && axis_len < 1.0001f))
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	return (EXIT_SUCCESS);
}

void	init_element(void *elem)
{
	const t_element	*self = elem;

	if (self->type == AmbientLight)
		init_ambient_light(elem);
	if (self->type == Camera)
		init_camera(elem);
	if (self->type == Light)
		init_light(elem);
	if (self->type == Plane)
		init_plane(elem);
	if (self->type == Sphere)
		init_sphere(elem);
	if (self->type == Cylinder)
		init_cylinder(elem);
}

void	element_iter(t_list *list, enum e_element_func e)
{
	if (e == Init)
	{
		while (list)
		{
			init_element(list->content);
			list = list->next;
		}
		return ;
	}
	while (list)
	{
		if (((t_element *)(list->content))->func[e])
			((t_element *)(list->content))->func[e](list->content);
		list = list->next;
	}
}
