/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/07 05:47:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include "../common.h"
# include "../util/element_util.h"

typedef struct s_cylinder
{
	struct s_element		base;
	struct s_cylinder_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		t_rgb		rgb;
		float		diameter;
		float		height;
	}						raw;
	struct s_cylinder_obj
	{
		float		radius;
		float		height;
	}						obj;
}	t_cylinder;

typedef struct s_circle
{
	t_point		center;
	t_vector3	axis;
	float		radius;
}	t_circle;

typedef struct s_cylinder_body_alias
{
	float		r2;
	t_vector3	w;
	float		vh;
	float		wh;
	float		l;
	t_vector3	in;
}	t_cylinder_body_alias;

extern int	hit_cylinder(t_cylinder *self, t_ray *r, t_range ra, t_hit *h);
extern int	init_cylinder(t_cylinder *self);
extern int	transform_cylinder(
				t_cylinder *self,
				const t_element *camera,
				enum e_transform_type type,
				t_vector3 delta);

#endif 
