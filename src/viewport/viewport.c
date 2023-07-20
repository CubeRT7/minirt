/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:34:23 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 10:26:30 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewport.h"

extern void	init_hook(struct s_viewport *view);

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
	init_hook(view);
	view->separated_render_max = vector3(
			(int)(1 + WINDOW_WIDTH / WINDOW_WIDTH_SEPARATE),
			(int)(1 + WINDOW_HEIGHT / WINDOW_HEIGHT_SEPARATE),
			0);
	return (EXIT_SUCCESS);
}
