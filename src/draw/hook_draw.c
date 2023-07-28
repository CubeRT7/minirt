/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 11:04:06 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw/draw.h"

static void	render_text(t_world *world)
{
	static const char	*edit = "edit....";
	static int			frame = 0;
	const int			len = (frame++ / 10) % 8;
	t_device *const		device = &world->device;

	if (world->render_mode & RENDER_ORIGINAL)
		put_str(device, vector3(5, -8, 0), ".", 1);
	if (world->render_mode & RENDER_AMBIENT)
		put_str(device, vector3(10, -8, 0), ".", 1);
	if (world->render_mode & RENDER_DIFFUSE)
		put_str(device, vector3(15, -8, 0), ".", 1);
	if (world->render_mode & RENDER_SPECULAR)
		put_str(device, vector3(20, -8, 0), ".", 1);
	if (world->selected == NULL)
	{
		frame = 0;
		return ;
	}
	put_str(device, vector3(10, 10, 0), world->selected->type_name, SIZE_MAX);
	put_str(device, vector3(10, 30, 0), edit, len);
}

int	hook_draw(void *param)
{
	t_world *const		world = param;
	t_device *const		device = &world->device;

	device->mouse.prev = device->mouse.curr;
	device->mouse.curr = get_mouse_pos(device);
	transform_objs_with_mouse(world);
	hook_draw_setting(param);
	mlx_clear_window(device->mlx, device->win);
	render_main_frame(world);
	render_text(world);
	mlx_put_image_to_window(device->mlx, device->win, device->img, 0, 0);
	return (EXIT_SUCCESS);
}
