/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 09:48:37 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATE_H
# define SIMULATE_H
# include "viewport.h"
# include "Element/AmbientLight/ambient_light.h"
# include "Element/Camera/camera.h"

typedef struct s_world
{
	t_vector3				axis;
	t_list					*objs;
	t_list					*lights;
	t_camera				*camera;
	t_ambient_light			*ambient_light;
	t_viewport				viewport;
	t_element				*selected;
	enum e_transform_type	transform_type;
}	t_world;

extern int	hook_draw(void *param);
extern int	hook_draw_setting(void *param);

extern void	rotate_camera(void *param);
extern void	move_camera(void *param);
extern void	transform_objs(void *param);
extern void	transform_objs_with_mouse(void *param);

extern int	simulate(
				t_list *ambient,
				t_list *camera,
				t_list *lights,
				t_list *objs);

#endif
