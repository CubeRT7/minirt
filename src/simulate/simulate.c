/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 05:22:05 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"
#include "simulate/util/simulate_util.h"

static void	_init_gui_setting(t_gui_setting *g, char *title)
{
	g->mlx = NULL;
	g->image = NULL;
	g->title = title;
	g->focal_length = DEFAULT_FOCAL_WIDTH;
	g->max_depth = DEFAULT_MAX_DEPTH;
	g->ignore_delta = DEFAULT_IGNORE_DELTA;
	g->sample_per_pixel = DEFAULT_SAMPLE_PER_PIXEL;
}

static int	_gui_setting(t_gui_setting *g, int width, int height, char *title)
{
	_init_gui_setting(g, title);
	g->mlx = mlx_init(width, height, g->title, true);
	if (g->mlx == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	g->image = mlx_new_image(g->mlx, width, height);
	if (g->image == NULL)
	{
		mlx_close_window(g->mlx);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	if (mlx_image_to_window(g->mlx, g->image, 0, 0) == -1)
	{
		mlx_close_window(g->mlx);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	return (EXIT_SUCCESS);
}

static int	_hook_setting(t_world *world)
{
	mlx_mouse_hook(world->gui.mlx, hook_mouse_event, world);
	if (!mlx_loop_hook(world->gui.mlx, hook_key_event, world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!mlx_loop_hook(world->gui.mlx, hook_draw_setting, world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!mlx_loop_hook(world->gui.mlx, hook_draw, world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	mlx_resize_hook(world->gui.mlx, hook_resize_event, &(world->gui));
	mlx_close_hook(world->gui.mlx, hook_close_event, &(world->gui));
	return (EXIT_SUCCESS);
}

int	simulate(t_list *ambient, t_list *camera, t_list *lights, t_list *objs)
{
	t_world	world;

	world.ambient_light = ambient->content;
	world.camera = camera->content;
	world.lights = lights;
	world.objs = objs;
	if (_gui_setting(&(world.gui), WINDOW_WIDTH, WINDOW_HEIGHT, TITLE))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	world_iter(&world, Init);
	world_iter(&world, Update);
	if (_hook_setting(&world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	mlx_loop(world.gui.mlx);
	mlx_terminate(world.gui.mlx);
	return (EXIT_SUCCESS);
}
