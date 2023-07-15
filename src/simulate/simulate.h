/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/15 12:55:35 by minjungk         ###   ########.fr       */
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
# define WINDOW_WIDTH 400
# define WINDOW_HEIGHT 300

# define DEFAULT_FOCAL_WIDTH 2.0f
# define DEFAULT_MAX_DEPTH 50
# define DEFAULT_IGNORE_DELTA 0.001f
# define DEFAULT_SAMPLE_PER_PIXEL 10

typedef struct s_mouse
{
	t_vector3	curr;
	t_vector3	prev[MAX_MOUSE_KEY];
	int			action[MAX_MOUSE_KEY];
}	t_mouse;

typedef struct s_gui_setting
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	t_mouse		mouse;
	int			keyboard[MAX_KEYBOARD];
	float		focal_length;
	float		max_depth;
	float		ignore_delta;
	float		sample_per_pixel;
}	t_gui_setting;

typedef struct s_world
{
	t_vector3		axis;
	t_list			*objs;
	t_list			*lights;
	t_camera		*camera;
	t_ambient_light	*ambient_light;
	t_gui_setting	gui;
}	t_world;

int	simulate(t_list *ambient, t_list *camera, t_list *lights, t_list *objs);

#endif
