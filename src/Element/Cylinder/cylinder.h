/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/10 01:51:12 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H
# include "../common.h"

typedef struct s_cylinder
{
	enum e_element			type;
	t_color					color;
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
		t_point		position;
		t_vector3	axis;
		t_color		color;
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

extern t_func	cylinder(enum e_element_func func);
extern int		debug_cylinder(void *param);
extern int		parse_cylinder(void *param, char **argv);
extern int		hit_cylinder(void *this, t_ray *r, t_range ra, t_hit *h);
extern int		init_cylinder(t_cylinder *self);

#endif 
