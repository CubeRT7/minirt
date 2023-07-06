/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/03 22:42:21 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "libcustom.h"
# include "libvector.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

enum e_vector_scope
{
	UnitScope,
	AllScope
};

typedef t_vector3	t_point;
typedef t_vector3	t_color;

typedef struct s_ray
{
	t_point		origin;
	t_vector3	direction;
}	t_ray;

enum e_element
{
	AmbientLight,
	Camera,
	Light,
	Plane,
	Sphere,
	Cylinder,
	MAX_ELEMENT_TYPE
};

typedef int			(*t_func)();

typedef struct s_element
{
	enum e_element	type;
	t_color			color;
}	t_element;

typedef struct s_range
{
	float	min;
	float	max;
}	t_range;

typedef struct s_hit
{
	float		t;
	t_point		p;
	t_vector3	normal;
	t_color		color;
}	t_hit;

enum e_element_func
{
	Debug,
	Serialize,
	Deserialize,
	Hit,
	Init,
	MAX_ELEMENT_FUNC
};

extern t_func	element(enum e_element type, enum e_element_func func);
extern int		parse_rgb(struct s_rgb *rgb, char *curr);
extern int		parse_vector3(t_vector3 *vector, char *curr, float scope);

#endif
