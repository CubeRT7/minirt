/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 02:08:40 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "simulate.h"

int	simulate(t_list *ambient, t_list *camera, t_list *lights, t_list *objs)
{
	t_world	world;

	ft_bzero(&world, sizeof(t_world));
	world.render_mode = RENDER_FULL;
	world.axis = v3_preset(V3_UP);
	world.ambient_light = ambient->content;
	world.camera = camera->content;
	world.lights = lights;
	world.objs = objs;
	if (create_device(&world.device) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	world_iter(&world, Init);
	world_iter(&world, Update);
	mlx_loop_hook(world.device.mlx, hook_draw, &world);
	mlx_loop(world.device.mlx);
	destroy_device(&world.device);
	return (EXIT_SUCCESS);
}

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
