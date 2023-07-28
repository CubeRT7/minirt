/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_util.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 06:58:48 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 15:11:46 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_UTIL_H
# define ELEMENT_UTIL_H
# define HAS_VALUE 0
# define NO_VALUE 1
# include "../element.h"

typedef struct s_abc
{
	double	a;
	double	b;
	double	c;
}	t_abc;

extern t_point		get_ray_point(const t_ray *ray, double t);
extern t_vector3	get_face_normal(t_ray ray, t_vector3 normal);
extern int			range_in(double t, t_range range);
extern int			range_not_in(double t, t_range range);
extern int			close_to_zero(double f);
extern int			quadratic_formula_root(t_abc abc, t_range range, double *x);
extern int			transform_element(
						t_element *self,
						const t_element *camera,
						enum e_transform_type type,
						t_vector3 delta);
extern t_color		rgb_to_color(t_rgb rgb);
extern void			rotate_element(
						t_element *elem,
						t_vector3 axis,
						float delta);

#endif
