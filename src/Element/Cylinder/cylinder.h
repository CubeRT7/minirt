/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 15:11:31 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include "../element.h"
# include "../util/element_util.h"

# define HIT_BODY 0b1
# define HIT_TOP 0b10
# define HIT_BOTTOM 0b100

typedef struct s_circle
{
	t_point		center;
	t_vector3	axis;
	double		radius;
}	t_circle;

typedef struct s_cylinder
{
	struct s_element		base;
	struct s_cylinder_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		t_rgb		rgb;
		double		diameter;
		double		height;
	}						raw;
	struct s_cylinder_obj
	{
		double		radius;
		double		height;
		t_circle	top;
		t_circle	bottom;
	}						obj;
}	t_cylinder;

typedef struct s_cylinder_body_alias
{
	double		r2;
	t_vector3	w;
	double		vh;
	double		wh;
	double		l;
	t_vector3	in;
}	t_cylinder_body_alias;

extern int	hit_cylinder(t_cylinder *self, t_ray *r, t_range ra, t_hit *h);
extern int	hit_color_cylinder(t_cylinder *self, t_hit *record);
extern int	init_cylinder(t_cylinder *self);
extern int	transform_cylinder(
				t_cylinder *self,
				const t_element *camera,
				enum e_transform_type type,
				t_vector3 delta);
extern int	update_cylinder(t_cylinder *self);

#endif
