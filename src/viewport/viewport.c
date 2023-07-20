/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:27:25 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/20 08:50:35 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

void	destroy_viewport(struct s_viewport *view)
{
	if (view == NULL)
		return ;
	if (view->img)
		mlx_destroy_image(view->mlx, view->img);
	view->img = NULL;
	if (view->win)
		mlx_destroy_window(view->mlx, view->win);
	view->win = NULL;
}

static void	_init_viewport(struct s_viewport *view)
{
	int	i;

	mlx_hook(view->win, KeyPress, KeyPressMask, key_press, view);
	mlx_hook(view->win, KeyRelease, KeyReleaseMask, key_release, view);
	mlx_hook(view->win, ButtonPress, ButtonPressMask, button_press, view);
	mlx_hook(view->win, ButtonRelease, ButtonReleaseMask, button_release, view);
	mlx_hook(view->win, DestroyNotify, 0, destroy_notify, view);
	view->separated_render_max = vector3(
			(int)(1 + WINDOW_WIDTH / WINDOW_WIDTH_SEPARATE),
			(int)(1 + WINDOW_HEIGHT / WINDOW_HEIGHT_SEPARATE),
			0);
	i = 0;
	while (i < MAX_MOUSE_KEY)
		view->mouse.action[i++] = MOUSE_IDLE;
}

int	create_viewport(struct s_viewport *view)
{
	if (view == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	view->mlx = mlx_init();
	if (view->mlx == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	view->size = (t_vector3){WINDOW_WIDTH, WINDOW_HEIGHT, 0};
	view->win = mlx_new_window(view->mlx, view->size.x, view->size.y, TITLE);
	if (view->win == NULL)
	{
		destroy_viewport(view);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	view->img = mlx_new_image(view->mlx, view->size.x, view->size.y);
	if (view->img == NULL)
	{
		destroy_viewport(view);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	_init_viewport(view);
	return (EXIT_SUCCESS);
}
