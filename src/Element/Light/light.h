/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/05 07:09:32 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../common.h"
# include "../util/element_util.h"

typedef struct s_light
{
	enum e_element			type;
	t_color					color;
	struct s_light_raw
	{
		t_point		coordinate;
		t_vector3	asix;
		t_rgb		rgb;
		float		ratio;
	}						raw;
	struct s_light_obj
	{
		t_point		position;
		t_vector3	asix;
		t_color		color;
		float		ratio;
	}						obj;
}	t_light;

extern t_func	light(enum e_element_func func);
extern int		debug_light(void *param);
extern int		hit_light(void *this, t_ray *r, t_range ra, t_hit *h);
extern int		init_light(t_light *self);

#endif 
