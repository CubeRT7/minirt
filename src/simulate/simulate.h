/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 08:49:40 by minjungk         ###   ########.fr       */
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

int	simulate(t_list *ambient, t_list *camera, t_list *lights, t_list *objs);

#endif
