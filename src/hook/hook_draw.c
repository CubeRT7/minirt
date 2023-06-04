/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/06/05 06:37:49 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	hook_draw(void *param)
{
	t_gui_setting	*gui;

	gui = param;
	for (int32_t i = 0; i < gui->window_width; ++i)
	{
		for (int32_t y = 0; y < gui->window_height; ++y)
		{
			mlx_put_pixel(gui->image, i, y,
				rand() % 0xFF << 24 |
				rand() % 0xFF << 16 |
				rand() % 0xFF << 8 |
				rand() % 0xFF);
		}
	}
}
