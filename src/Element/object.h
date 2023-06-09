/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:07:28 by yonshin           #+#    #+#             */
/*   Updated: 2023/06/09 12:09:29 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include "common.h"
# include "Element/AmbientLight/ambient_light.h"
# include "Element/Camera/camera.h"
# include "Element/Light/light.h"
# include "Element/Plane/plane.h"
# include "Element/Sphere/sphere.h"
# include "Element/Cylinder/cylinder.h"

typedef struct s_obj
{
	enum e_element	type;
}	t_obj;

typedef void	*(*t_new_object)(void *raw);
extern void		*new_object(enum e_element type, void *raw);

typedef void	(*t_destroy_object)(void *object);
extern void		destory_object(void *object);

typedef int		(*t_hit)(void *object, t_ray *ray);
extern int		hit(void *object, t_ray *ray);

#endif
