/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:10:36 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/20 09:51:39 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "device.h"

int	button_press(int button, int x, int y, void *param)
{
	t_device *const	device = param;

	if (x < 0 || x >= device->size.x)
		return (EXIT_SUCCESS);
	if (y < 0 || y >= device->size.y)
		return (EXIT_SUCCESS);
	if (device->mouse.action[button] == MOUSE_PRESS)
		device->mouse.action[button] = MOUSE_REPEAT;
	else
		device->mouse.action[button] = MOUSE_PRESS;
	return (EXIT_SUCCESS);
}

int	button_release(int button, int x, int y, void *param)
{
	t_device *const	device = param;

	(void)x;
	(void)y;
	device->mouse.action[button] = MOUSE_IDLE;
	return (EXIT_SUCCESS);
}
