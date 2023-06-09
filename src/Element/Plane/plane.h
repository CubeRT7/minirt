/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 19:41:08 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "../common.h"

typedef struct s_plane
{
	enum e_element			type;
	struct s_plane_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		t_rgb		rgb;
	}						raw;
	struct s_plane_obj
	{
		int			tbd;
	}						obj;
}	t_plane;

extern void	parse_debug_plane(void *param);
extern int	parse_plane(void *param, char **argv);
extern void	*new_plane(void *param);
extern void	destroy_plane(void *object);
extern int	hit_plane(void *object, t_ray *ray);

#endif 
