/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 15:11:35 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../element.h"
# include "../util/element_util.h"

typedef struct s_light
{
	struct s_element		base;
	struct s_light_raw
	{
		t_point		coordinate;
		t_vector3	axis;
		t_rgb		rgb;
		double		ratio;
	}						raw;
	struct s_light_obj
	{
		double		ratio;
	}						obj;
}	t_light;

extern int		init_light(t_light *self);

#endif 
