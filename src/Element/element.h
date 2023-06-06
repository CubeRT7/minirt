/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:22:54 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/07 07:14:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H
# include "AmbientLight/ambient_light.h"
# include "Camera/camera.h"
# include "Light/light.h"
# include "Plane/plane.h"
# include "Sphere/sphere.h"
# include "Cylinder/cylinder.h"

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

struct s_element
{
	const char	*type;
	size_t		size;
	int			(*parse)(void *, char **);
};

extern t_list	**get_elements(void);
extern void		clear_elements(void);
extern int		append_element(t_list **elements, char **cols);

#endif
