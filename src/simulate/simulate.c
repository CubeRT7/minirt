/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 09:18:23 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate.h"
#include "simulate/util/simulate_util.h"

static void	_clean_viewport(t_viewport *view)
{
	if (view->img)
		mlx_destroy_image(view->mlx, view->img);
	view->img = NULL;
	if (view->win)
		mlx_destroy_window(view->mlx, view->win);
	view->win = NULL;
}

static int	_viewport_setting(t_viewport *view)
{
	int	i;

	ft_bzero(view, sizeof(t_viewport));
	i = 0;
	while (i < MAX_MOUSE_KEY)
	{
		view->mouse.action[i] = MOUSE_IDLE;
		++i;
	}
	view->mlx = mlx_init();
	if (view->mlx == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	view->size = (t_vector3){WINDOW_WIDTH, WINDOW_HEIGHT, 0};
	view->win = mlx_new_window(view->mlx, view->size.x, view->size.y, TITLE);
	if (view->win == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	view->img = mlx_new_image(view->mlx, view->size.x, view->size.y);
	if (view->img == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	view->separated_render_max = vector3(
			(int)(1 + WINDOW_WIDTH / WINDOW_WIDTH_SEPARATE),
			(int)(1 + WINDOW_HEIGHT / WINDOW_HEIGHT_SEPARATE),
			0);
	return (EXIT_SUCCESS);
}

static void	_hook_setting(t_viewport *view)
{
	mlx_hook(view->win, KeyPress, KeyPressMask, key_press, view);
	mlx_hook(view->win, KeyRelease, KeyReleaseMask, key_release, view);
	mlx_hook(view->win, ButtonPress, ButtonPressMask, button_press, view);
	mlx_hook(view->win, ButtonRelease, ButtonReleaseMask, button_release, view);
	mlx_hook(view->win, DestroyNotify, 0, destroy_notify, view);
}

int	simulate(t_list *ambient, t_list *camera, t_list *lights, t_list *objs)
{
	t_world	world;

	ft_bzero(&world, sizeof(t_world));
	world.axis = v3_preset(V3_UP);
	world.ambient_light = ambient->content;
	world.camera = camera->content;
	world.lights = lights;
	world.objs = objs;
	if (_viewport_setting(&world.viewport) == EXIT_FAILURE)
	{
		_clean_viewport(&world.viewport);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	_hook_setting(&world.viewport);
	world_iter(&world, Init);
	world_iter(&world, Update);
	mlx_loop_hook(world.viewport.mlx, hook_draw, &world);
	mlx_loop(world.viewport.mlx);
	_clean_viewport(&world.viewport);
	return (EXIT_SUCCESS);
}
