/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 06:21:57 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "simulate/util/simulate_util.h"
#include "simulate/draw/draw.h"
#define DELTA 0.001f
#define BIGVALUE 99999999.0f

#include "Element/Light/light.h"

t_color	ray_color(t_world *world, t_ray *ray, int depth)
{
	t_hit					rec;
	t_ray					light_ray;
	t_list					*next;
	t_light					*light;
	t_color					light_color;
	t_vector3				direction;
	float					length;
	float					dot1;
	const t_ambient_light	*ambient_light = world->ambient_light;

	if (depth <= 0)
		return (vector3(0, 0, 0));
	if (hit(world->objs, ray, (t_range){DELTA, BIGVALUE}, &rec))
	{
		next = world->lights;
		light_color = vector3(0, 0, 0);
		while (next)
		{
			light = next->content;
			next = next->next;
			direction = v3_sub(light->base.position, rec.p);
			length = v3_magnitude(direction);
			light_ray = (t_ray){rec.p, v3_normalize(direction)};
			if (hit(world->objs, &light_ray, (t_range){ DELTA, length }, NULL))
				continue;
			dot1 = v3_dot(light_ray.direction, rec.normal);
			if (dot1 < 0)
				continue;
			light_color = v3_add(light_color, v3_mul(vector3(dot1, dot1, dot1), light->obj.ratio));
		}
		light_color.x = light_color.x > 1 ? 1 : light_color.x;
		light_color.y = light_color.y > 1 ? 1 : light_color.y;
		light_color.z = light_color.z > 1 ? 1 : light_color.z;
		light_color.x = (ambient_light->obj.ratio * ambient_light->base.color.x + (1 - ambient_light->obj.ratio) * light_color.x);
		light_color.y = (ambient_light->obj.ratio * ambient_light->base.color.y + (1 - ambient_light->obj.ratio) * light_color.y);
		light_color.z = (ambient_light->obj.ratio * ambient_light->base.color.z + (1 - ambient_light->obj.ratio) * light_color.z);
		return ((t_color){
			light_color.x * rec.color.x,
			light_color.y * rec.color.y,
			light_color.z * rec.color.z
		});
	}
	return (vector3(0, 0, 0));
}

#include "Element/Camera/camera.h"
static t_ray	get_camera_ray(void *camera, int width, int height, int x, int y)
{
	const t_camera	*cam = camera;

	float		u = (float)x / width;
	float		v = (float)y / height;
	t_vector3	direction = cam->obj.viewport_lower_left;
	direction = v3_add(direction, v3_mul(cam->obj.viewport_horizontal, u));
	direction = v3_add(direction, v3_mul(cam->obj.viewport_vertical, v));
	direction = v3_normalize(direction);
	t_vector3 front = v3_normalize(vector3(cam->base.axis.x, 0, cam->base.axis.z));
	t_vector3 right = v3_normalize(v3_cross(front, vector3(0, 1, 0)));
	float h_angle = acosf(v3_dot(vector3(0, 0, -1), front) * 0.99999f) * (front.x < 0 ? 1 : -1);
	float v_angle = acosf(v3_dot(front, cam->base.axis) * 0.99999f) * (cam->base.axis.y < 0 ? -1 : 1);
	direction = v3_rotate_axis(direction, vector3(0, 1, 0), h_angle);
	direction = v3_rotate_axis(direction, right, v_angle);
	return ((t_ray){cam->base.position, direction});
}

void	hook_draw(void *param)
{
	t_world *const		world = param;
	mlx_image_t	*const	img = world->gui.image;
	uint32_t			x;
	uint32_t			y;
	t_ray				ray;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			ray = get_camera_ray(world->camera, img->width, img->height, x, y);
			mlx_put_pixel(img, x, img->height - y - 1,
				color_to_pixel(ray_color(world, &ray, 50)));
			++y;
		}
		++x;
	}
}
