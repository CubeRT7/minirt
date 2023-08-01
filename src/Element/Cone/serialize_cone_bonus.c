/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_cone_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 02:05:14 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/parse_util.h"
#include "../Element/Cone/cone_bonus.h"

int	serialize_cone(int fd, t_element *element)
{
	t_cone *const	self = element;

	if (serialize_vector3(fd, self->base.position) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(' ', fd);
	if (serialize_vector3(fd, self->base.front) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(' ', fd);
	if (serialize_double(fd, self->radius * 2) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(' ', fd);
	if (serialize_double(fd, self->height) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(' ', fd);
	serialize_rgb(fd, self->base.color);
	return (EXIT_SUCCESS);
}
