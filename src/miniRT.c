/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/04 05:37:36 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "simulate.h"

int	main(int argc, char **argv)
{
	struct s_rt_file	rt;

	errno = 0;
	ft_bzero(&rt, sizeof(struct s_rt_file));
	if (import_file(&rt, argc, argv))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (simulate(rt.ambient_light, rt.camera, rt.lights, rt.objs))
	{
		clean_rt(&rt);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	clean_rt(&rt);
	return (EXIT_SUCCESS);
}
