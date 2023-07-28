/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:36:38 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 11:12:33 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "device.h"
# include "Element/common.h"
# include "Element/AmbientLight/ambient_light.h"
# include "Element/Camera/camera.h"
# define DELTA 0.00000001
# define BIGVALUE 99999999.0

enum e_render_mode
{
	RENDER_ORIGINAL = 0x01,
	RENDER_AMBIENT = 0x02,
	RENDER_DIFFUSE = 0x04,
	RENDER_SPECULAR = 0x08,
	RENDER_FULL = \
		RENDER_ORIGINAL | RENDER_AMBIENT | RENDER_DIFFUSE | RENDER_SPECULAR
};

typedef struct s_world
{
	t_device				device;
	unsigned int			render_mode;
	t_vector3				axis;
	t_list					*objs;
	t_list					*lights;
	t_camera				*camera;
	t_ambient_light			*ambient_light;
	t_element				*selected;
	enum e_transform_type	transform_type;
}	t_world;

extern int			hook_draw(void *param);
extern int			hook_draw_setting(void *param);

extern void			rotate_camera(void *param);
extern void			move_camera(void *param);
extern void			transform_objs(void *param);
extern void			transform_objs_with_mouse(void *param);

extern void			world_iter(t_world *world, enum e_element_func e);
extern int			hit(t_list *objs, t_ray *r, t_range ran, t_hit *h);
extern t_ray		get_camera_ray(t_camera *camera,
						t_vector3 screen,
						t_vector3 pos,
						t_vector3 delta);
extern t_element	*select_element(t_world *world, t_vector3 pos);

#endif
