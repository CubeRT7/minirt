/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/17 16:41:33 by minjungk         ###   ########.fr       */
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

enum e_element_func
{
	Debug,
	Serialize,
	Deserialize,
	Hit,
	Init,
	Update,
	Transform,
	MAX_ELEMENT_FUNC
};

enum e_transform_type
{
	None = 0x0,
	X = 0x1,
	Y = 0x2,
	Z = 0x4,
	Height = 0x8,
	Radius = 0x10,
	Position = 0x100,
	Rotation = 0x200,
	Scaling = 0x400,
};

typedef struct s_element
{
	enum e_element	type;
	char			*type_name;
	t_point			position;
	t_vector3		front;
	t_vector3		up;
	t_vector3		right;
	t_color			color;
	t_func			func[MAX_ELEMENT_FUNC];
}	t_element;

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
	t_element	*elem;
}	t_hit;

extern void		init_element(void *elem);
extern void		element_iter(t_list *list, enum e_element_func e);
extern int		parse_rgb(struct s_rgb *rgb, char *curr);
extern int		parse_vector3(t_vector3 *vector, char *curr, int scope);

#endif
