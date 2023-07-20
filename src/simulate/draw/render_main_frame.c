/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:13:07 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 09:08:34 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	_update_next_render_idx(t_workspace *workspace)
{
	workspace->separated_render_curr.x++;
	if (workspace->separated_render_curr.x >= workspace->separated_render_max.x)
	{
		workspace->separated_render_curr.x = 0;
		workspace->separated_render_curr.y++;
	}
	if (workspace->separated_render_curr.y >= workspace->separated_render_max.y)
		workspace->separated_render_curr.y = 0;
}

static int	_get_pixel(t_world *w, t_vector3 pos)
{
	static const t_vector3	v[] = {
		(t_vector3){0, 0.5, 0},
		(t_vector3){-0.5, -0.5, 0},
		(t_vector3){0.5, -0.5, 0}};
	t_ray					ray;
	int						idx;
	t_color					color;
	t_color					res;

	res = v3_preset(V3_ZERO);
	idx = 0;
	while (idx < 3)
	{
		ray = get_camera_ray(w->camera, w->workspace.size, pos, v[idx]);
		color = ray_color(&ray, w->objs, w->ambient_light, w->lights);
		res = v3_add(res, color);
		idx++;
	}
	return (color_to_pixel(v3_mul(res, 0.333)));
}

void	render_main_frame(t_world *world)
{
	t_workspace *const	workspace = &world->workspace;
	t_vector3			pos;
	int					pixel_color;

	pos.x = workspace->separated_render_curr.x;
	while (pos.x < workspace->size.x)
	{
		pos.y = workspace->separated_render_curr.y;
		while (pos.y < workspace->size.y)
		{
			if (pos.x > workspace->size.x || pos.y > workspace->size.y)
				break ;
			pixel_color = _get_pixel(world, pos);
			set_pixel(world, pos.x, workspace->size.y - pos.y - 1, pixel_color);
			pos.y += workspace->separated_render_max.y;
		}
		pos.x += workspace->separated_render_max.x;
	}
	_update_next_render_idx(workspace);
}
