/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 19:41:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H
# include "../common.h"

typedef struct s_sphere
{
	enum e_element			type;
	struct s_sphere_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		t_rgb		rgb;
		float		diameter;
	}						raw;
	struct s_sphere_obj
	{
		int			tbd;
	}						obj;
}	t_sphere;

extern void	parse_debug_sphere(void *param);
extern int	parse_sphere(void *param, char **argv);
extern void	*new_sphere(void *param);
extern void	destroy_sphere(void *object);
extern int	hit_sphere(void *object, t_ray *ray);

#endif 
