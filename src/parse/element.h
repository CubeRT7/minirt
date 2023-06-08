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
# include "Element/AmbientLight/ambient_light.h"
# include "Element/Camera/camera.h"
# include "Element/Light/light.h"
# include "Element/Plane/plane.h"
# include "Element/Sphere/sphere.h"
# include "Element/Cylinder/cylinder.h"

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
