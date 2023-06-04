/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:18:35 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/31 07:58:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <fcntl.h>
# include "Element/AmbientLight/ambient_light.h"
# include "Element/Camera/camera.h"
# include "Element/Light/light.h"
# include "Element/Plane/plane.h"
# include "Element/Sphere/sphere.h"
# include "Element/Cylinder/cylinder.h"

struct s_scene
{
	t_list	*ambient_light;
	t_list	*camera;
	t_list	*light;
	t_list	*plane;
	t_list	*sphere;
	t_list	*cylinder;
};

int	parse(struct s_scene *scene, int argc, char **argv);

#endif
