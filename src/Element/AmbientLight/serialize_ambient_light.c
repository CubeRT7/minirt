/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_ambient_light.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:12:56 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 01:59:16 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../util/parse_util.h"
#include "../Element/AmbientLight/ambient_light.h"

int	serialize_ambient_light(int fd, t_element *element)
{
	t_ambient_light *const	self = element;

	if (serialize_double(fd, self->ratio) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(' ', fd);
	serialize_rgb(fd, self->base.color);
	return (EXIT_SUCCESS);
}
