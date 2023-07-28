/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:36:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 20:57:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "../element.h"
# include "../util/element_util.h"

typedef struct s_camera
{
	struct s_element	base;
	t_vector3			viewport_lower_left;
	t_vector3			viewport_horizontal;
	t_vector3			viewport_vertical;
	double				ratio;
	double				fov_radian;
}	t_camera;

extern int		init_camera(t_camera *self);
extern int		update_camera(t_camera *self);

#endif 
