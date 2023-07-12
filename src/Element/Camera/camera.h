/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:36:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/12 05:39:32 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "../common.h"
# include "../util/element_util.h"

typedef struct s_camera
{
	struct s_element			base;
	struct s_camera_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		float		fov;
	}							raw;
	struct s_camera_obj
	{
		int			rotate_flag;
		t_vector3	cursor_pos;
		t_vector3	viewport_lower_left;
		t_vector3	viewport_horizontal;
		t_vector3	viewport_vertical;
		float		ratio;
		float		fov_radian;
	}							obj;
}	t_camera;

extern int		init_camera(t_camera *self);
extern int		update_camera(t_camera *self);

#endif 
