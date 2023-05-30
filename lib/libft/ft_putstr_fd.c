/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:29:45 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/06 02:00:44 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	while (s && s[len])
	{
		if (++len == SIZE_MAX)
		{
			write(fd, s, len);
			s += len;
			len = 0;
		}
	}
	write(fd, s, len);
}
