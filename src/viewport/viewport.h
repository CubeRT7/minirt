/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:34:23 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 10:25:53 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H
# include "mlx.h"
# include "libcustom.h"
# include "libvector.h"

# define TITLE "CubeRT7"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
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
// viewport
/* ************************************************************************** */

typedef struct s_viewport
{
	void		*mlx;
	void		*win;
	void		*img;
	t_vector3	size;
	t_vector3	separated_render_max;
	t_vector3	separated_render_curr;
	t_mouse		mouse;
	int			keyboard[MAX_KEYBOARD];
}	t_viewport;

extern void	destroy_viewport(struct s_viewport *viewport);
extern int	create_viewport(struct s_viewport *viewport);

#endif
