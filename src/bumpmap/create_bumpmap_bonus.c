/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bumpmap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:13:57 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 16:21:08 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bumpmap_bonus.h"
#include "bumpmap_private_bonus.h"

static t_img	*_create_img(t_img *img, void *mlx, char *path)
{
	int	bpp;
	int	endian;

	img->img = mlx_xpm_file_to_image(mlx, path, &(img->width), &(img->height));
	if (img->img == NULL)
		return (NULL);
	img->mlx = mlx;
	img->addr = mlx_get_data_addr(img->img, &bpp, &(img->sizeline), &endian);
	return (img);
}

static int	_validate(t_bump_map **bumpmaps, int idx)
{
	if (idx <= 0 || idx >= BUMPMAP_ARR_SIZE)
		return (EXIT_FAILURE);
	if (*bumpmaps == NULL)
		*bumpmaps = ft_calloc(BUMPMAP_ARR_SIZE, sizeof(t_bump_map));
	if (*bumpmaps == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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
	ft_bzero(map, sizeof(t_bump_map));
}

int	create_bumpmap(int idx, void *mlx, char *bit_path, char *normal_path)
{
	t_bump_map **const	bumpmap = bumpmap_arr();
	t_bump_map			*map;

	if (_validate(bumpmap, idx))
		return (EXIT_FAILURE);
	map = *bumpmap;
	_create_img(&(map[idx].bit), mlx, bit_path);
	_create_img(&(map[idx].normal), mlx, normal_path);
	if (map[idx].bit.img == NULL || map[idx].normal.img == NULL)
	{
		_free_bumpmap(map + idx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
