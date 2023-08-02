/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/30 17:21:59 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"
#include "miniRT.h"
#include "bumpmap/bumpmap_bonus.h"

static void	_init_bumpmaps(void *mlx)
{
	create_bumpmap(1, mlx,
		"data/bumpmap/wall.xpm", "data/bumpmap/wall_norm.xpm");
	create_bumpmap(2, mlx,
		"data/bumpmap/plane.xpm", "data/bumpmap/stone_norm.xpm");
}

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
	_init_bumpmaps(world.device.mlx);
	_init_world(&world, &rt);
	mlx_loop_hook(world.device.mlx, main_loop, &world);
	mlx_loop(world.device.mlx);
	clear_bumpmaps();
	destroy_device(&world.device);
	clean_rt(&rt);
	return (EXIT_SUCCESS);
}
