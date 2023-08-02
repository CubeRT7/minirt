/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:09:51 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/31 15:26:25 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H
# include "libcustom.h"
# include "libvector.h"

# define HIT 0b1

typedef t_vector3	t_point;
typedef t_vector3	t_color;

enum e_element
{
	AmbientLight,
	Camera,
	Light,
	Plane,
	Sphere,
	Cylinder,
	Cone,
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
	int				mapid;
	void			*bumpmap;
}	t_element;

extern void		element_iter(t_list *list, enum e_element_func e);

#endif
