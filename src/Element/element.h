/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 18:02:32 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H
# include "common.h"

# define HIT 0b1

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
	HitColor,
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

extern void		init_element(void *elem);
extern void		element_iter(t_list *list, enum e_element_func e);

#endif