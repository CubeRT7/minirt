/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_sphere_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 01:59:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/parse_util.h"
#include "../Element/Sphere/sphere.h"

int	serialize_sphere(int fd, t_element *element)
{
	t_sphere *const	self = element;

	if (serialize_vector3(fd, self->base.position) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(' ', fd);
	if (serialize_double(fd, self->radius * 2) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(' ', fd);
	serialize_rgb(fd, self->base.color);
	ft_putchar_fd(' ', fd);
	if (serialize_double(fd, self->base.mapid), 0 == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	return (EXIT_SUCCESS);
}
