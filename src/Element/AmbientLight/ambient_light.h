/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 23:28:09 by minjungk         ###   ########.fr       */
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
		int			tbd;
	}						obj;
}	t_ambient_light;

extern void	parse_debug_ambient_light(void *param);
extern int	parse_ambient_light(void *param, char **argv);

#endif 
