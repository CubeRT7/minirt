/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:38:24 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/20 10:23:42 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "workspace.h"

/*
 * Reference: X11/X.h
 */
enum e_mask
{
	NoEventMask = 0L,
	KeyPressMask = (1L<<0),
	KeyReleaseMask = (1L<<1),
	ButtonPressMask = (1L<<2),
	ButtonReleaseMask = (1L<<3),
	EnterWindowMask = (1L<<4),
	LeaveWindowMask = (1L<<5),
	PointerMotionMask = (1L<<6),
	PointerMotionHintMask = (1L<<7),
	Button1MotionMask = (1L<<8),
	Button2MotionMask = (1L<<9),
	Button3MotionMask = (1L<<10),
	Button4MotionMask = (1L<<11),
	Button5MotionMask = (1L<<12),
	ButtonMotionMask = (1L<<13),
	KeymapStateMask = (1L<<1),
	ExposureMask = (1L<<15),
	VisibilityChangeMask = (1L<<16),
	StructureNotifyMask = (1L<<17),
	ResizeRedirectMask = (1L<<18),
	SubstructureNotifyMask = (1L<<19),
	SubstructureRedirectMask = (1L<<20),
	FocusChangeMask = (1L<<21),
	PropertyChangeMask = (1L<<22),
	ColormapChangeMask = (1L<<23),
	OwnerGrabButtonMask = (1L<<24)
};

enum e_event
{
	KeyPress = 2,
	KeyRelease = 3,
	ButtonPress = 4,
	ButtonRelease = 5,
	MotionNotify = 6,
	EnterNotify = 7,
	LeaveNotify = 8,
	FocusIn = 9,
	FocusOut = 10,
	KeymapNotify = 11,
	Expose = 12,
	GraphicsExpose = 13,
	NoExpose = 14,
	VisibilityNotify = 15,
	CreateNotify = 16,
	DestroyNotify = 17,
	UnmapNotify = 18,
	MapNotify = 19,
	MapRequest = 20,
	ReparentNotify = 21,
	ConfigureNotify = 22,
	ConfigureRequest = 23,
	GravityNotify = 24,
	ResizeRequest = 25,
	CirculateNotify = 26,
	CirculateRequest = 27,
	PropertyNotify = 28,
	SelectionClear = 29,
	SelectionRequest = 30,
	SelectionNotify = 31,
	ColormapNotify = 32,
	ClientMessage = 33,
	MappingNotify = 34,
	LASTEvent = 35
};

extern int	destroy_notify(void *param);
extern int	key_press(int keycode, void *param);
extern int	key_release(int keycode, void *param);
extern int	button_press(int button, int x, int y, void *param);
extern int	button_release(int button, int x, int y, void *param);

void	init_hook(struct s_workspace *view)
{
	int	i;

	i = 0;
	while (i < MAX_MOUSE_KEY)
		view->mouse.action[i++] = MOUSE_IDLE;
	i = 0;
	while (i < MAX_KEYBOARD)
		view->keyboard[i++] = 0;
	mlx_hook(view->win, DestroyNotify, 0, destroy_notify, view);
	mlx_hook(view->win, KeyPress, KeyPressMask, key_press, view);
	mlx_hook(view->win, KeyRelease, KeyReleaseMask, key_release, view);
	mlx_hook(view->win, ButtonPress, ButtonPressMask, button_press, view);
	mlx_hook(view->win, ButtonRelease, ButtonReleaseMask, button_release, view);
}
