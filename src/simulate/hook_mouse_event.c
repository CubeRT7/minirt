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

#include "viewport.h"

int	button_press(int button, int x, int y, void *param)
{
	t_viewport *const	viewport = param;

	if (x < 0 || x >= viewport->size.x)
		return (EXIT_SUCCESS);
	if (y < 0 || y >= viewport->size.y)
		return (EXIT_SUCCESS);
	if (viewport->mouse.action[button] == MOUSE_PRESS)
		viewport->mouse.action[button] = MOUSE_REPEAT;
	else
		viewport->mouse.action[button] = MOUSE_PRESS;
	return (EXIT_SUCCESS);
}

int	button_release(int button, int x, int y, void *param)
{
	t_viewport *const	viewport = param;

	(void)x;
	(void)y;
	viewport->mouse.action[button] = MOUSE_IDLE;
	return (EXIT_SUCCESS);
}
