/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/07 05:48:42 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H
# include "../common.h"
# include "../util/element_util.h"

typedef struct s_ambient_light
{
	struct s_element		base;
	struct s_ambient_light_raw
	{
		float		ratio;
		t_rgb		rgb;
	}						raw;
	struct s_ambient_light_obj
	{
		float	ratio;
	}						obj;
}	t_ambient_light;

extern t_func	ambient_light(enum e_element_func func);
extern int		debug_ambient_light(void *param);
extern int		init_ambient_light(t_ambient_light *self);

#endif 
