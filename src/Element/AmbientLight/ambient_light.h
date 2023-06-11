/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/10 01:39:56 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H
# include "../common.h"

typedef struct s_ambient_light
{
	enum e_element			type;
	struct s_ambient_light_raw
	{
		float		ratio;
		t_rgb		rgb;
	}						raw;
	struct s_ambient_light_obj
	{
		float	ratio;
		t_color	color;
	}						obj;
}	t_ambient_light;

extern t_func	ambient_light(enum e_element_func func);
extern int		debug_ambient_light(void *param);
extern int		parse_ambient_light(void *param, char **argv);
extern int		hit_ambient_light(void *this, t_ray *r, t_range ra, t_hit *h);
extern int		init_ambient_light(t_ambient_light *self);

#endif 
