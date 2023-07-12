/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/07 05:49:30 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../common.h"
# include "../util/element_util.h"

typedef struct s_light
{
	struct s_element		base;
	struct s_light_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		t_rgb		rgb;
		float		ratio;
	}						raw;
	struct s_light_obj
	{
		float		ratio;
	}						obj;
}	t_light;

extern int		init_light(t_light *self);

#endif 
