/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/15 12:49:09 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"
#include "simulate/util/simulate_util.h"

static void	_clean_gui(t_gui_setting *g)
{
	if (g->img)
		mlx_destroy_image(g->mlx, g->img);
	g->img = NULL;
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	g->win = NULL;
}

static int	_gui_setting(t_gui_setting *g)
{
	int	i;

	ft_bzero(g, sizeof(t_gui_setting));
	i = 0;
	while (i < MAX_MOUSE_KEY)
	{
		g->mouse.action[i] = MOUSE_IDLE;
		++i;
	}
	g->mlx = mlx_init();
	if (g->mlx == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	g->screen = (t_vector3){WINDOW_WIDTH, WINDOW_HEIGHT, 0};
	g->win = mlx_new_window(g->mlx, g->screen.x, g->screen.y, TITLE);
	if (g->win == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	g->img = mlx_new_image(g->mlx, g->screen.x, g->screen.y);
	if (g->img == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	return (EXIT_SUCCESS);
}

static int	_hook_setting(t_world *world)
{
	t_gui_setting *const	g = &world->gui;

	mlx_hook(g->win, KeyPress, KeyPressMask, key_press, world);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, key_release, world);
	mlx_hook(g->win, ButtonPress, ButtonPressMask, button_press, world);
	mlx_hook(g->win, ButtonRelease, ButtonReleaseMask, button_release, world);
	mlx_hook(g->win, MotionNotify, ButtonMotionMask, motion_notify, world);
	mlx_hook(g->win, DestroyNotify, 0, hook_close_event, world);
	mlx_loop_hook(g->mlx, hook_draw, world);
	return (EXIT_SUCCESS);
}

int	simulate(t_list *ambient, t_list *camera, t_list *lights, t_list *objs)
{
	t_world	world;

	world.axis = (t_vector3){0, 1, 0};
	world.ambient_light = ambient->content;
	world.camera = camera->content;
	world.lights = lights;
	world.objs = objs;
	if (_gui_setting(&world.gui) == EXIT_FAILURE)
	{
		_clean_gui(&world.gui);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	if (_hook_setting(&world))
	{
		_clean_gui(&world.gui);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	world_iter(&world, Init);
	world_iter(&world, Update);
	mlx_loop(world.gui.mlx);
	_clean_gui(&world.gui);
	return (EXIT_SUCCESS);
}
