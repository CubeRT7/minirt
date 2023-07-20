/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_event_macos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 10:36:34 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "device.h"

/*
 * Reference:
 * /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library
 * /Frameworks/Carbon.framework/Versions/A
 * /Frameworks/HIToolbox.framework/Versions/A
 * /Headers/Events.h 
 * */
static const int	g_keycode[MAX_KEYBOARD] = {
[KEYBOARD_RETURN] = 0x0024,
[KEYBOARD_TAB] = 0x0030,
[KEYBOARD_ESCAPE] = 0x0035,
[KEYBOARD_SPACE] = 0x31,
[KEYBOARD_LSHIFT] = 0x101,
[KEYBOARD_w] = 0x0D,
[KEYBOARD_a] = 0x00,
[KEYBOARD_s] = 0x01,
[KEYBOARD_d] = 0x02,
[KEYBOARD_p] = 0x23,
[KEYBOARD_t] = 0x11,
[KEYBOARD_h] = 0x04,
[KEYBOARD_r] = 0x0F,
[KEYBOARD_x] = 0x07,
[KEYBOARD_y] = 0x10,
[KEYBOARD_z] = 0x06,
[KEYBOARD_q] = 0x0C,
[KEYBOARD_e] = 0x0E
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
