/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 11:11:54 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "miniRT.h"

static void	_init_world(struct s_world *world, struct s_rt_file *rt)
{
	world->render_mode = RENDER_FULL;
	world->axis = v3_preset(V3_UP);
	world->ambient_light = rt->ambient_light->content;
	world->camera = rt->camera->content;
	world->lights = rt->lights;
	world->objs = rt->objs;
	world_iter(world, Init);
	world_iter(world, Update);
}

int	main(int argc, char **argv)
{
	struct s_rt_file	rt;
	struct s_world		world;

	errno = 0;
	ft_bzero(&rt, sizeof(struct s_rt_file));
	if (import_file(&rt, argc, argv))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ft_bzero(&world, sizeof(struct s_world));
	if (create_device(&world.device) == EXIT_FAILURE)
	{
		clean_rt(&rt);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	_init_world(&world, &rt);
	mlx_loop_hook(world.device.mlx, hook_draw, &world);
	mlx_loop(world.device.mlx);
	destroy_device(&world.device);
	clean_rt(&rt);
	return (EXIT_SUCCESS);
}
