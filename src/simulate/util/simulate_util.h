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
# define DELTA 0.001f
# define BIGVALUE 99999999.0f
# include "simulate.h"
# include "Element/common.h"

extern void			world_iter(t_world *world, enum e_element_func e);
extern int			hit(t_list *objs, t_ray *r, t_range ran, t_hit *h);
extern t_ray		get_camera_ray(t_camera *cam, t_vector3 s, t_vector3 p);
extern t_element	*select_element(t_world *world, t_vector3 pos);
extern void			put_string(t_world *w, t_vector3 p, const char *s, int len);
extern void			set_pixel(t_world *world, int x, int y, int color);
extern t_vector3	get_mouse_pos(t_world *world);

#endif
