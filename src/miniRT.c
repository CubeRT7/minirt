/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/31 08:25:17 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	struct s_scene	scene;

	if (parse(&scene, argc, argv))
	{
		perror("Error\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
