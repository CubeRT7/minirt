/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/05 06:02:13 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H
# include "../common.h"

typedef struct s_parsed_ambient_light
{
	float				ratio;
	struct s_rgb		rgb;
}	t_parsed_ambient_light;

typedef struct s_ambient_light
{
	enum e_element	type;
	// TODO: add param
}	t_ambient_light;

extern void	parse_debug_ambient_light(void *param);
extern int	parse_ambient_light(void *param, char **argv);
extern void	*new_ambient_light(void *param);
extern void	destroy_ambient_light(void *object);
extern int	hit_ambient_light(void *object, t_ray *ray);

#endif 
