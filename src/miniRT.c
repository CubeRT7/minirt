/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/03 20:33:35 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	struct s_scene	scene;

	if (parse(&scene, argc, argv))
		return (ft_error(__func__, __FILE__, __LINE__));
	return (EXIT_SUCCESS);
}
