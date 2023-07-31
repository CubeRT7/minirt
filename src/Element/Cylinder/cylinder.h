/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:49 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/31 04:22:01 by minjungk         ###   ########.fr       */
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
	struct s_element	base;
	double				radius;
	double				height;
	t_circle			top;
	t_circle			bottom;
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

#endif
