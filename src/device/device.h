/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:34:23 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/22 15:45:28 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEVICE_H
# define DEVICE_H
# include "mlx.h"
# include "libcustom.h"
# include "libvector.h"

# ifndef WINDOW_WIDTH
#  define WINDOW_WIDTH 0
# endif
# ifndef WINDOW_HEIGHT
#  define WINDOW_HEIGHT 0
# endif
# define TITLE "CubeRT7"
# define WINDOW_WIDTH_SEPARATE 128
# define WINDOW_HEIGHT_SEPARATE 128

/* ************************************************************************** */
// mouse
/* ************************************************************************** */

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

typedef struct s_mouse
{
	t_vector3	prev;
	t_vector3	curr;
	int			action[MAX_MOUSE_KEY];
}	t_mouse;

/* ************************************************************************** */
// keyboard
/* ************************************************************************** */

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

/* ************************************************************************** */
// device
/* ************************************************************************** */

typedef struct s_device
{
	void		*mlx;
	void		*win;
	void		*img;
	t_vector3	size;
	t_vector3	separated_render_max;
	t_vector3	separated_render_curr;
	t_mouse		mouse;
	int			keyboard[MAX_KEYBOARD];
}	t_device;

extern void			destroy_device(struct s_device *device);
extern int			create_device(struct s_device *device);
extern t_vector3	get_mouse_pos(void *mlx, void *win);
extern void			put_str(
						t_device *device,
						t_vector3 position,
						const char *str,
						size_t len);
extern void			set_pixel(t_device *device, int x, int y, int color);
extern uint32_t		color_to_pixel(t_vector3 c);

#endif
