/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/07 05:49:42 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "../common.h"
# include "../util/element_util.h"

typedef struct s_sphere
{
	struct s_element		base;
	struct s_sphere_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		t_rgb		rgb;
		double		diameter;
	}						raw;
	struct s_sphere_obj
	{
		double		radius;
	}						obj;
}	t_sphere;

extern int	hit_sphere(t_sphere *self, t_ray *r, t_range ra, t_hit *h);
extern int	init_sphere(t_sphere *self);
extern int	transform_sphere(
				t_sphere *self,
				const t_element *camera,
				enum e_transform_type type,
				t_vector3 delta);

#endif 
