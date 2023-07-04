/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/05 07:08:59 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "../common.h"
# include "../util/element_util.h"

typedef struct s_plane
{
	enum e_element			type;
	t_color					color;
	struct s_plane_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		t_rgb		rgb;
	}						raw;
	struct s_plane_obj
	{
		t_point		position;
		t_vector3	axis;
		t_color		color;
	}						obj;
}	t_plane;

extern t_func	plane(enum e_element_func func);
extern int		debug_plane(void *param);
extern int		hit_plane(void *this, t_ray *r, t_range ra, t_hit *h);
extern int		init_plane(t_plane *self);

#endif 
