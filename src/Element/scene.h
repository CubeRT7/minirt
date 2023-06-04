/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:22:54 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/04 23:47:18 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "AmbientLight/ambient_light.h"
# include "Camera/camera.h"
# include "Light/light.h"
# include "Plane/plane.h"
# include "Sphere/sphere.h"
# include "Cylinder/cylinder.h"

enum e_scene
{
	AmbientLight,
	Camera,
	Light,
	Plane,
	Sphere,
	Cylinder,
	MAX_SCENE
};

extern t_list	**get_scene(void);
extern void		clear_scene(void);

#endif
