/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/06/07 06:29:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	hook_draw(void *param)
{
	t_world	*world;

	world = param;
	for (int32_t i = 0; i < world->gui.mlx->width; ++i)
	{
		for (int32_t y = 0; y < world->gui.mlx->height; ++y)
		{
			mlx_put_pixel(world->gui.image, i, y,
				rand() % 0xFF << 24 |
				rand() % 0xFF << 16 |
				rand() % 0xFF << 8 |
				rand() % 0xFF);
		}
	}
}
