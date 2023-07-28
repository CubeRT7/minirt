/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:52:36 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 20:10:31 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "libcustom.h"
# include "libvector.h"

typedef t_vector3	t_point;
typedef t_vector3	t_color;

typedef struct s_ray
{
	t_point		origin;
	t_vector3	direction;
}	t_ray;

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_hit
{
	double		t;
	t_point		p;
	t_vector3	normal;
	t_color		color;
	void		*elem;
	int			hit_status;
}	t_hit;

#endif
