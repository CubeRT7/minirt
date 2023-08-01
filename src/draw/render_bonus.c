/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:13:07 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/31 08:21:45 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	render_image(t_world *world);

static void	_render_text(t_world *world)
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

void	render(t_world *world)
{
	t_device *const		device = &world->device;

	mlx_clear_window(device->mlx, device->win);
	render_image(world);
	_render_text(world);
	mlx_put_image_to_window(device->mlx, device->win, device->img, 0, 0);
}
