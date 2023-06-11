/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:36:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/10 01:51:03 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "../common.h"

typedef struct s_camera
{
	enum e_element				type;
	t_color						color;
	struct s_camera_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		float		fov;
	}							raw;
	struct s_camera_obj
	{
		int			tbd;
		t_point		position;
		t_vector3	angle;
	}							obj;
}	t_camera;

extern t_func	camera(enum e_element_func func);
extern int		debug_camera(void *param);
extern int		parse_camera(void *param, char **argv);
extern int		hit_camera(void *this, t_ray *r, t_range ra, t_hit *h);
extern int		init_camera(t_camera *self);

#endif 
