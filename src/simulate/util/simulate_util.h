/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate_util.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 07:05:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/09 07:06:02 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATE_UTIL_H
# define SIMULATE_UTIL_H
# define DELTA 0.001f
# define BIGVALUE 99999999.0f
# include "simulate.h"
# include "Element/common.h"

typedef struct s_screen
{
	struct
	{
		uint32_t	w;
		uint32_t	h;
	};
	struct
	{
		uint32_t	x;
		uint32_t	y;
	};
}	t_screen;

extern void		world_iter(t_world *world, enum e_element_func e);
extern int		hit(t_list *objs, t_ray *ray, t_range range, t_hit *record);
extern t_ray	get_camera_ray(void *camera, t_screen screen, t_screen pos);

#endif
