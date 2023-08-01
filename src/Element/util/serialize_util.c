/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 23:28:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 01:59:02 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_util.h"

int	serialize_double(int fd, double v)
{
	char *const	tmp = ft_ftoa(v, 6);

	if (tmp == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putstr_fd(tmp, fd);
	free(tmp);
	return (EXIT_SUCCESS);
}

int	serialize_vector3(int fd, t_vector3 v)
{
	if (serialize_double(fd, v.x) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(',', fd);
	if (serialize_double(fd, v.y) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_putchar_fd(',', fd);
	if (serialize_double(fd, v.z) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	return (EXIT_SUCCESS);
}

void	serialize_rgb(int fd, t_color c)
{
	const uint8_t	r = fmin(255, c.x * 255);
	const uint8_t	g = fmin(255, c.y * 255);
	const uint8_t	b = fmin(255, c.z * 255);

	ft_putnbr_fd(r, fd);
	ft_putchar_fd(',', fd);
	ft_putnbr_fd(g, fd);
	ft_putchar_fd(',', fd);
	ft_putnbr_fd(b, fd);
}
