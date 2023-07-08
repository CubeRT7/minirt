/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/08 18:59:22 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"

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
	if (!mlx_loop_hook(world->gui.mlx, hook_draw, world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	mlx_resize_hook(world->gui.mlx, hook_resize_event, &(world->gui));
	mlx_close_hook(world->gui.mlx, hook_close_event, &(world->gui));
	return (EXIT_SUCCESS);
}

static int	_init_world(t_world *world)
{
	t_list		*curr;
	t_element	*elem;
	t_func		func;

	init_ambient_light(world->ambient_light);
	init_camera(world->camera);
	curr = world->lights;
	while (curr)
	{
		elem = curr->content;
		func = element(elem->type, Init);
		if (func(elem))
			return (ft_error(__func__, __FILE__, __LINE__, 0));
		curr = curr->next;
	}
	curr = world->objs;
	while (curr)
	{
		elem = curr->content;
		func = element(elem->type, Init);
		if (func(elem))
			return (ft_error(__func__, __FILE__, __LINE__, 0));
		curr = curr->next;
	}
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
	if (_init_world(&world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (_hook_setting(&world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	mlx_loop(world.gui.mlx);
	mlx_terminate(world.gui.mlx);
	return (EXIT_SUCCESS);
}
