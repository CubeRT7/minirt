/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:55:46 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/05 06:34:36 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcustom.h"

int	ft_error(const char *func, char *file, int line, int sub_errno)
{
	static int	depth = 0;
	const int	save_errno = errno;

	if (depth++ == 0)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	if (DEBUG)
	{
		ft_putstr_fd("\tat ", STDERR_FILENO);
		ft_putstr_fd((char *)func, STDERR_FILENO);
		ft_putchar_fd('(', STDERR_FILENO);
		ft_putstr_fd(file, STDERR_FILENO);
		ft_putchar_fd(':', STDERR_FILENO);
		ft_putnbr_fd(line, STDERR_FILENO);
		ft_putchar_fd(')', STDERR_FILENO);
	}
	if (save_errno)
		errno = save_errno;
	else if (sub_errno)
		errno = sub_errno;
	if (errno)
		perror(":");
	else if (DEBUG)
		ft_putchar_fd('\n', STDERR_FILENO);
	errno = 0;
	return (EXIT_FAILURE);
}
