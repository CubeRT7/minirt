/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/17 17:03:28 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "simulate/util/simulate_util.h"
#include "simulate/draw/draw.h"

static void	_update_next_render_idx(t_gui_setting *gui)
{
	gui->separated_render_curr.x++;
	if (gui->separated_render_curr.x >= gui->separated_render_max.x)
	{
		gui->separated_render_curr.x = 0;
		gui->separated_render_curr.y++;
	}
	if (gui->separated_render_curr.y >= gui->separated_render_max.y)
		gui->separated_render_curr.y = 0;
}

static void	render_mode(t_world *world)
{
	static const char	*edit = "edit....";
	static int			frame = 0;
	const int			len = (frame++ / 10) % 8;

	if (world->selected == NULL)
	{
		frame = 0;
		return ;
	}
	put_string(world, vector3(10, 10, 0), edit, len);
}

static void	render_main_frame(t_world *world)
{
	t_gui_setting *const	gui = &world->gui;
	t_vector3				pos;
	t_ray					ray;

	pos.x = gui->separated_render_curr.x;
	while (pos.x < gui->screen.x)
	{
		pos.y = gui->separated_render_curr.y;
		while (pos.y < gui->screen.y)
		{
			if (pos.x > gui->screen.x || pos.y > gui->screen.y)
				break ;
			ray = get_camera_ray(world->camera, gui->screen, pos);
			set_pixel(world, pos.x, gui->screen.y - pos.y - 1,
				color_to_pixel(ray_color(&ray,
						world->objs, world->ambient_light, world->lights)));
			pos.y += gui->separated_render_max.y;
		}
		pos.x += gui->separated_render_max.x;
	}
	_update_next_render_idx(gui);
}

int	hook_draw(void *param)
{
	t_world *const			world = param;
	t_gui_setting *const	gui = &world->gui;

	gui->mouse.prev = gui->mouse.curr;
	gui->mouse.curr = get_mouse_pos(world);
	transform_objs_with_mouse(world);
	hook_draw_setting(param);
	mlx_clear_window(gui->mlx, gui->win);
	render_main_frame(world);
	render_mode(world);
	mlx_put_image_to_window(gui->mlx, gui->win, gui->img, 0, 0);
	return (EXIT_SUCCESS);
}
