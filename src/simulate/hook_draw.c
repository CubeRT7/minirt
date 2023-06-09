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
	t_world *const	world = param;
	int				x;
	int				y;

	x = -1;
	while (++x < world->gui.mlx->width)
	{
		y = -1;
		while (++y < world->gui.mlx->height)
		{
			mlx_put_pixel(world->gui.image, x, y, \
				rand() % 0xFF << 24 | \
				rand() % 0xFF << 16 | \
				rand() % 0xFF << 8 | \
				rand() % 0xFF);
		}
	}
}
