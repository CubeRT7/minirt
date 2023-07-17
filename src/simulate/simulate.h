/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/17 15:36:02 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATE_H
# define SIMULATE_H

# include "mlx.h"
# include "hook.h"
# include "libcustom.h"
# include "Element/AmbientLight/ambient_light.h"
# include "Element/Camera/camera.h"

# define TITLE "CubeRT7"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_mouse
{
	t_vector3	curr;
	t_vector3	press[MAX_MOUSE_KEY];
	int			action[MAX_MOUSE_KEY];
}	t_mouse;

typedef struct s_gui_setting
{
	void		*mlx;
	void		*win;
	void		*img;
	t_vector3	screen;
	t_vector3	separated_render_max;
	t_vector3	separated_render_curr;
	t_mouse		mouse;
	int			keyboard[MAX_KEYBOARD];
	float		focal_length;
	float		max_depth;
	float		ignore_delta;
	float		sample_per_pixel;
}	t_gui_setting;

typedef struct s_world
{
	t_vector3				axis;
	t_list					*objs;
	t_list					*lights;
	t_camera				*camera;
	t_ambient_light			*ambient_light;
	t_gui_setting			gui;
	t_element				*selected;
	enum e_transform_type	transform_type;
}	t_world;

int	simulate(t_list *ambient, t_list *camera, t_list *lights, t_list *objs);

#endif
