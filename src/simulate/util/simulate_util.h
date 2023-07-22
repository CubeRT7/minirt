/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 07:05:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/17 17:13:03 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATE_UTIL_H
# define SIMULATE_UTIL_H
# define DELTA 0.00000001
# define BIGVALUE 99999999.0
# include "simulate.h"
# include "Element/common.h"

extern void			world_iter(t_world *world, enum e_element_func e);
extern int			hit(t_list *objs, t_ray *r, t_range ran, t_hit *h);
extern t_ray		get_camera_ray(t_camera *camera,
						t_vector3 screen,
						t_vector3 pos,
						t_vector3 delta);
extern t_element	*select_element(t_world *world, t_vector3 pos);

#endif
