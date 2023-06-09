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
		int			tbd;
	}						obj;
}	t_cylinder;

extern t_func	cylinder(enum e_element_func func);
extern int		debug_cylinder(void *param);
extern int		parse_cylinder(void *param, char **argv);

#endif 
