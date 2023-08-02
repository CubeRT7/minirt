/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_bumpmaps_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:23:33 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 16:23:42 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bumpmap_bonus.h"
#include "bumpmap_private_bonus.h"

static void	_free_img(t_img *img)
{
	if (img == NULL)
		return ;
	mlx_destroy_image(img->mlx, img->img);
	img->mlx = NULL;
	img->img = NULL;
}

static void	_free_bumpmap(t_bump_map *map)
{
	if (map == NULL)
		return ;
	if (map->bit.mlx)
		_free_img(&(map->bit));
	if (map->normal.mlx)
		_free_img(&(map->normal));
}

void	clear_bumpmaps(void)
{
	t_bump_map **const	bumpmap = bumpmap_arr();
	t_bump_map			*map;
	int					i;

	if (*bumpmap == NULL)
		return ;
	map = *bumpmap;
	i = 0;
	while (i < BUMPMAP_ARR_SIZE)
	{
		_free_bumpmap(map + i);
		i++;
	}
	free(map);
}
