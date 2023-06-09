/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 19:41:06 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../common.h"

typedef struct s_light
{
	enum e_element			type;
	struct s_light_raw
	{
		t_point		coordinate;
		t_vector3	asix;
		t_rgb		rgb;
		float		ratio;
	}						raw;
	struct s_light_obj
	{
		int			tbd;
	}						obj;
}	t_light;

extern void	parse_debug_light(void *param);
extern int	parse_light(void *param, char **argv);
extern void	*new_light(void *param);
extern void	destroy_light(void *object);
extern int	hit_light(void *object, t_ray *ray);

#endif 
