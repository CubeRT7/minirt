/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 00:36:21 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/parse_util.h"
#include "../Element/Plane/plane.h"

int	serialize_plane(int fd, t_element *element)
{
	t_plane *const	self = element;

	if (serialize_vector3(fd, self->base.position) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(' ', fd);
	if (serialize_vector3(fd, self->base.front) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(' ', fd);
	serialize_rgb(fd, self->base.color);
	return (EXIT_SUCCESS);
}
