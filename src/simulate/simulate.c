/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:20:11 by yonshin          ###   ########.fr       */
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
	if (!mlx_loop_hook(world->gui.mlx, hook_key_event, world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!mlx_loop_hook(world->gui.mlx, hook_draw, world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	mlx_resize_hook(world->gui.mlx, hook_resize_event, &(world->gui));
	mlx_close_hook(world->gui.mlx, hook_close_event, &(world->gui));
	return (EXIT_SUCCESS);
}

static int	_filter_append(const t_list *next, enum e_element t, t_list **res)
{
	t_element	*elem;
	t_list		*new_node;
	t_list		*list;

	list = NULL;
	while (next)
	{
		elem = next->content;
		next = next->next;
		if (elem->type != t)
			continue ;
		new_node = ft_lstnew(elem);
		if (new_node == NULL)
		{
			ft_lstclear(&list, NULL);
			return (ft_error(__func__, __FILE__, __LINE__, 0));
		}
		ft_lstadd_back(&list, new_node);
	}
	if (list)
		ft_lstadd_back(res, list);
	return (EXIT_SUCCESS);
}

static int	_init_objs(t_list *objs)
{
	t_element	*elem;
	t_func		func;

	while (objs)
	{
		elem = objs->content;
		func = element(elem->type, Init);
		if (func(elem))
			return (ft_error(__func__, __FILE__, __LINE__, 0));
		objs = objs->next;
	}
	return (EXIT_SUCCESS);
}

int	simulate(t_list *objs, int width, int height, char *title)
{
	t_world	world;
	t_list	*obj;

	ft_bzero(&world, sizeof(t_world));
	world.objs = objs;
	if (_filter_append(world.objs, Light, &(world.lights)))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	obj = NULL;
	if (_filter_append(world.objs, Camera, &obj) || obj == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	world.camera = obj->content;
	obj = NULL;
	if (_filter_append(world.objs, AmbientLight, &obj) || obj == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	world.ambient_light = obj->content;
	if (_gui_setting(&(world.gui), width, height, title))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (_init_objs(world.objs))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (_hook_setting(&world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	mlx_loop(world.gui.mlx);
	mlx_terminate(world.gui.mlx);
	return (EXIT_SUCCESS);
}
