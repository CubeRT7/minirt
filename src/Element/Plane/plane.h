/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/05 06:03:30 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "../common.h"

typedef struct s_parsed_plane
{
	t_point		coordinate;
	t_vector3	axis;
	t_rgb		rgb;
}	t_parsed_plane;

// TODO: add param
typedef struct s_plane
{
	enum e_element	type;
}	t_plane;

extern void	parse_debug_plane(void *param);
extern int	parse_plane(void *param, char **argv);
extern void	*new_plane(void *param);
extern void	destroy_plane(void *object);
extern int	hit_plane(void *object, t_ray *ray);

#endif 
