/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/06 18:15:18 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	exit_minirt(int exit_code)
{
	clear_scene();
	return (exit_code);
}

int	main(int argc, char **argv)
{
	errno = 0;
	if (parse(get_scene(), argc, argv))
		return (exit_minirt(ft_error(__func__, __FILE__, __LINE__, 0)));
	return (exit_minirt(EXIT_SUCCESS));
}
