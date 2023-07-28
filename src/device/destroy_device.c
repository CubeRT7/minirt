/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_device.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:15:48 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 13:16:24 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "device.h"

void	destroy_device(struct s_device *device)
{
	if (device == NULL)
		return ;
	if (device->img)
		mlx_destroy_image(device->mlx, device->img);
	device->img = NULL;
	if (device->win)
		mlx_destroy_window(device->mlx, device->win);
	device->win = NULL;
}
