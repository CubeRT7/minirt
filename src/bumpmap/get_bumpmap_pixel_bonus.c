/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bumpmap_pixel_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:02:02 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 16:18:52 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bumpmap_bonus.h"
#include "bumpmap_private_bonus.h"

static double	_fix(double d)
{
	if ((int)d == d)
		return (0);
	if (d < 0)
		return (d - ((int)d - 1));
	return (d - (int)d);
}

static int	_get_color_from_image(t_img *img, int x, int y)
{
	if (x == img->width)
		x = img->width - 1;
	if (y == img->height)
		y = img->height - 1;
	return (*((int *)(img->addr + img->sizeline * y + (x * 4))));
}

t_vector3	get_bumpmap_pixel(int idx, t_vector3 uv, int type)
{
	t_bump_map *const	bumpmaps = (*bumpmap_arr());
	t_vector3			v;
	int					pixel;

	if (idx <= 0 || idx >= BUMPMAP_ARR_SIZE)
		return (v3_preset(V3_ZERO));
	if (bumpmaps == NULL || bumpmaps[idx].map->mlx == NULL)
		return (v3_preset(V3_ZERO));
	v.x = _fix(uv.x) * bumpmaps[idx].map[type].width;
	v.y = _fix(uv.y) * bumpmaps[idx].map[type].height;
	pixel = _get_color_from_image(&(bumpmaps[idx].map[type]), v.x, v.y);
	if (type == BITMAP)
		return ((t_vector3){
			((0x00FF0000 & pixel) >> 16) / 255.0,
			((0x0000FF00 & pixel) >> 8) / 255.0,
			((0x000000FF & pixel) >> 0) / 255.0,
		});
	return ((t_vector3){
		((0x00FF0000 & pixel) >> 16) / 255.0 * 2 - 1,
		((0x0000FF00 & pixel) >> 8) / 255.0 * 2 - 1,
		((0x000000FF & pixel) >> 0) / 255.0 * 2 - 1,
	});
}
