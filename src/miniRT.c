/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 21:51:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/07 07:02:48 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libgui.h"
#include "hook.h"

#define TITLE "CubeRT7"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

static int	_hook_setting(t_gui_setting *g)
{
	if (!mlx_loop_hook(g->mlx, hook_key_event, g))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!mlx_loop_hook(g->mlx, hook_draw, g))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	mlx_resize_hook(g->mlx, hook_resize_event, g);
	mlx_close_hook(g->mlx, hook_close_event, g);
	return (EXIT_SUCCESS);
}

static int	exit_minirt(int exit_code)
{
	clear_elements();
	return (exit_code);
}

int	main(int argc, char **argv)
{
	t_gui_setting	gui;

	errno = 0;
	if (parse(get_elements(), argc, argv))
		return (exit_minirt(ft_error(__func__, __FILE__, __LINE__, 0)));
	if (gui_setting(&gui, WINDOW_WIDTH, WINDOW_HEIGHT, TITLE))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (_hook_setting(&gui))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	gui_open_window(&gui);
	return (exit_minirt(EXIT_SUCCESS));
}
