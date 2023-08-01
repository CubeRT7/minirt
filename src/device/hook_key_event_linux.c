/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_event_linux.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/02 01:40:59 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "device.h"

/*
 * Reference: X11/keysymdef.h
 */
static const int	g_keycode[MAX_KEYBOARD] = {
[KEYBOARD_RETURN] = 0xFF0D,
[KEYBOARD_TAB] = 0xFF09,
[KEYBOARD_ESCAPE] = 0xFF1B,
[KEYBOARD_SPACE] = 0x020,
[KEYBOARD_LSHIFT] = 0xFFE1,
[KEYBOARD_w] = 0x77,
[KEYBOARD_a] = 0x61,
[KEYBOARD_s] = 0x73,
[KEYBOARD_d] = 0x64,
[KEYBOARD_p] = 0x070,
[KEYBOARD_t] = 0x074,
[KEYBOARD_h] = 0x068,
[KEYBOARD_r] = 0x072,
[KEYBOARD_x] = 0x078,
[KEYBOARD_y] = 0x079,
[KEYBOARD_z] = 0x07a,
[KEYBOARD_q] = 0x071,
[KEYBOARD_e] = 0x065,
[KEYBOARD_F1] = 0xffbe,
[KEYBOARD_F2] = 0xffbf,
[KEYBOARD_F3] = 0xffc0,
[KEYBOARD_F4] = 0xffc1,
[KEYBOARD_F12] = 0xffc9,
};

int	key_press(int keycode, void *param)
{
	int				i;
	t_device *const	device = param;

	if (keycode == g_keycode[KEYBOARD_ESCAPE])
		exit(EXIT_SUCCESS);
	i = 0;
	while (i < MAX_KEYBOARD)
	{
		if (keycode == g_keycode[i])
		{
			device->keyboard[i] = 1;
			return (EXIT_SUCCESS);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	key_release(int keycode, void *param)
{
	int				i;
	t_device *const	device = param;

	i = 0;
	while (i < MAX_KEYBOARD)
	{
		if (keycode == g_keycode[i])
		{
			device->keyboard[i] = 0;
			return (EXIT_SUCCESS);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}
