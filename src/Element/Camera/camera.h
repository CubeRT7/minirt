/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:36:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/08 19:09:59 by minjungk         ###   ########.fr       */
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
		struct
		{
			int		rotate_flag;
			int		cursor_xy[2];
		};
		float		fov_radian;
	}							obj;
}	t_camera;

extern t_func	camera(enum e_element_func func);
extern int		debug_camera(void *param);
extern int		hit_camera(void *self, t_ray *r, t_range ra, t_hit *h);
extern int		init_camera(t_camera *self);
extern void		init_view(t_camera *self);

#endif 
