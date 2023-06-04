/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_resize_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:24 by yonshin           #+#    #+#             */
/*   Updated: 2023/06/05 06:37:30 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"

void	hook_resize_event(int width, int height, void *param)
{
	t_gui_setting	*gui;

	gui = param;
	gui->window_width = width;
	gui->window_height = height;
	mlx_resize_image(gui->image, width, height);
}
