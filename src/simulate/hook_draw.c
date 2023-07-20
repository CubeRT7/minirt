/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 13:26:55 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate/util/simulate_util.h"
#include "simulate/draw/draw.h"

static void	render_text(t_world *world)
{
	static const char	*edit = "edit....";
	static int			frame = 0;
	const int			len = (frame++ / 10) % 8;

	if (world->selected == NULL)
	{
		frame = 0;
		return ;
	}
	put_str(world, vector3(10, 10, 0), world->selected->type_name, SIZE_MAX);
	put_str(world, vector3(10, 30, 0), edit, len);
}

int	hook_draw(void *param)
{
	t_world *const		world = param;
	t_workspace *const	space = &world->workspace;

	space->mouse.prev = space->mouse.curr;
	space->mouse.curr = get_mouse_pos(world);
	transform_objs_with_mouse(world);
	hook_draw_setting(param);
	mlx_clear_window(space->mlx, space->win);
	render_main_frame(world);
	render_text(world);
	mlx_put_image_to_window(space->mlx, space->win, space->img, 0, 0);
	return (EXIT_SUCCESS);
}
