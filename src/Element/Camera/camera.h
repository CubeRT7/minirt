/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:36:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/05 06:03:22 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H
# include "../common.h"

typedef struct s_parsed_camera
{
	struct s_vector4	coordinate;
	struct s_vector4	axis;
	float				fov;
}	t_parsed_camera;

typedef struct s_camera
{
	enum e_element	type;
	// TODO: add param
}	t_camera;

extern void	parse_debug_camera(void *param);
extern int	parse_camera(void *param, char **argv);
extern void	*new_camera(void *param);
extern void	destroy_camera(void *object);
extern int	hit_camera(void *object, t_ray *ray);

#endif 
