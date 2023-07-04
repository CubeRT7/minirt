/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/05 07:06:24 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "../common.h"
# include "../util/element_util.h"

typedef struct s_sphere
{
	enum e_element			type;
	t_color					color;
	struct s_sphere_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		t_rgb		rgb;
		float		diameter;
	}						raw;
	struct s_sphere_obj
	{
		t_point		position;
		t_vector3	axis;
		t_color		color;
		float		radius;
	}						obj;
}	t_sphere;

extern t_func	sphere(enum e_element_func func);
extern int		debug_sphere(void *param);
extern int		hit_sphere(void *this, t_ray *r, t_range ra, t_hit *h);
extern int		init_sphere(t_sphere *self);

#endif 
