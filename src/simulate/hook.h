/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:34:23 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/17 16:50:00 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H
# include "mlx.h"
# include "Element/common.h"

extern int	hook_draw(void *param);
extern int	hook_draw_setting(void *param);
extern int	hook_close_event(void *param);

extern int	key_press(int keycode, void *param);
extern int	key_release(int keycode, void *param);
extern int	button_press(int button, int x, int y, void *param);
extern int	button_release(int button, int x, int y, void *param);

extern void	rotate_camera(void *param);
extern void	move_camera(void *param);
extern void	transform_objs(void *param);
extern void	transform_objs_with_mouse(void *param);

enum e_mouse_action
{
	MOUSE_PRESS = 0,
	MOUSE_RELEASE = 1,
	MOUSE_REPEAT = 2,
	MOUSE_IDLE = 3
};

enum e_mouse_key
{
	MOUSE_BUTTON_UNKNOWN = 0,
	MOUSE_BUTTON_LEFT = 1,
	MOUSE_BUTTON_RIGHT	= 2,
	MOUSE_BUTTON_MIDDLE	= 3,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
	MAX_MOUSE_KEY
};

enum e_keyboard_key
{
	KEYBOARD_RETURN,
	KEYBOARD_TAB,
	KEYBOARD_ESCAPE,
	KEYBOARD_SPACE,
	KEYBOARD_LSHIFT,
	KEYBOARD_w,
	KEYBOARD_a,
	KEYBOARD_s,
	KEYBOARD_d,
	KEYBOARD_p,
	KEYBOARD_t,
	KEYBOARD_h,
	KEYBOARD_r,
	KEYBOARD_x,
	KEYBOARD_y,
	KEYBOARD_z,
	KEYBOARD_q,
	KEYBOARD_e,
	MAX_KEYBOARD
};

# ifndef __LINUX__
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
# else
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
[KEYBOARD_e] = 0x065
};
# endif

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

#endif
