/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 09:23:48 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"
#include "simulate/util/simulate_util.h"

int	simulate(t_list *ambient, t_list *camera, t_list *lights, t_list *objs)
{
	t_world	world;

	ft_bzero(&world, sizeof(t_world));
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
