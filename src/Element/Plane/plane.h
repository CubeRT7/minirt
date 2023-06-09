/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/10 00:48:06 by minjungk         ###   ########.fr       */
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

extern int	debug_plane(void *param);
extern int	parse_plane(void *param, char **argv);

#endif 
