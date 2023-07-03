/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:39:46 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#define DELTA 0.001f
#define BIGVALUE 99999999

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void     debug_handler(void *param)
{
	t_element *elem = param;
	t_func func = element(elem->type, Debug);

	func(param);
}

t_color back_ground_color(t_ray ray)
{
	float t = (ray.direction.y + 1) * 0.5f;
	return v3_add(vector3(1-t, 1-t, 1-t), v3_mul(vector3(0.5, 0.7, 1.0), t));
}

int hit(t_world *world, t_ray *ray, t_range range, t_hit *record)
{
	t_hit temp_rec;
	const t_list *next = world->objs;
	int hit_anything = 0;
	float closest_so_far = range.max;
	
	while (next) {

		const t_element *elem = next->content;
		const t_func elem_hit = element(elem->type, Hit);
		
		if (elem_hit(elem, ray, (t_range){ range.min, closest_so_far }, &temp_rec)) {
			hit_anything = 1;
			closest_so_far = temp_rec.t;
			if (record != NULL) {
				temp_rec.color = elem->color;
				*record = temp_rec;
			}
		}

		next = next->next;

	}
	return hit_anything;
}

#include "Element/Light/light.h"
#include "Element/AmbientLight/ambient_light.h"

t_color ray_color(t_world *world, t_ray *ray, int depth)
{
	t_hit rec;

	if (depth <= 0) {
		return vector3(0, 0, 0);
	}
	if (hit(world, ray, (t_range){ DELTA, BIGVALUE }, &rec)) {
		t_color color;

		if (rec.scatter(ray, &rec, &color)) {
			t_color c = ray_color(world, ray, depth - 1);
			return (t_color){color.x * c.x, color.y * c.y, color.z * c.z};
		}
		t_list *next = world->lights;
		t_color lightColor = vector3(0, 0, 0);
		while (next) {
			t_light *light = next->content;
			next = next->next;
			t_vector3 direction = v3_sub(light->obj.position, rec.p);
			float length = v3_magnitude(direction);
			t_ray lightRay = {rec.p, v3_normalize(direction)};
			if (hit(world, &lightRay, (t_range){ DELTA, length }, NULL))
				continue;
			
			float dot1 = v3_dot_prod(lightRay.direction, rec.normal);
			if (dot1 < 0)
				continue;
			lightColor = v3_add(lightColor, v3_mul(vector3(dot1, dot1, dot1), light->obj.ratio));
		}
		lightColor.x = lightColor.x > 1 ? 1 : lightColor.x;
		lightColor.y = lightColor.y > 1 ? 1 : lightColor.y;
		lightColor.z = lightColor.z > 1 ? 1 : lightColor.z;
		const t_ambient_light *ambient_light = world->ambient_light;
		lightColor.x = (ambient_light->obj.ratio * ambient_light->obj.color.x + (1 - ambient_light->obj.ratio) * lightColor.x);
		lightColor.y = (ambient_light->obj.ratio * ambient_light->obj.color.y + (1 - ambient_light->obj.ratio) * lightColor.y);
		lightColor.z = (ambient_light->obj.ratio * ambient_light->obj.color.z + (1 - ambient_light->obj.ratio) * lightColor.z);
		return (t_color){
			lightColor.x * color.x,
			lightColor.y * color.y,
			lightColor.z * color.z
		};
	}
	return vector3(0, 0, 0);
}



t_element *find(t_list *list, enum e_element type)
{
	while (list)
	{
		if (((t_element *)(list->content))->type == type)
			return list->content;
		list = list->next;
	}
	return NULL;
}

#include "Element/Camera/camera.h"
static t_ray get_camera_ray(void *camera, int width, int height, int x, int y)
{
	const t_camera *cam = camera;

	float aspect_ratio = (float)height / width;
	float viewport_width = 2.0f;
	float viewport_height =  aspect_ratio * viewport_width;
	float fov_half = cam->obj.fov_radian * 0.5f;
	if (sin(fov_half) == 0) {
		t_vector3 cam_axis = v3_rotate(vector3(0, 0, -1), v3_sub(cam->obj.angle, vector3(M_PI_2, M_PI_2, M_PI)));
		return ((t_ray){ cam->obj.position, cam_axis });
	}
	float focal_length = cos(fov_half) / sin(fov_half);

	t_point origin = cam->obj.position;
	t_vector3 horizontal = vector3(viewport_width, 0, 0);
	t_vector3 vertical = vector3(0, viewport_height, 0);
	t_point lower_left_corner = origin;
	lower_left_corner = v3_sub(lower_left_corner, v3_mul(horizontal, 0.5f));
	lower_left_corner = v3_sub(lower_left_corner, v3_mul(vertical, 0.5f));
	lower_left_corner = v3_sub(lower_left_corner, vector3(0, 0, focal_length));
	// TODO: camera fov 적용

	float u = (float)x / width;
	float v = (float)y / height;
	t_vector3 direction = lower_left_corner;
	direction = v3_add(direction, v3_mul(horizontal, u));
	direction = v3_add(direction, v3_mul(vertical, v));
	direction = v3_rotate(direction, v3_sub(cam->obj.angle, vector3(M_PI_2, M_PI_2, M_PI)));
	direction = v3_normalize(direction);
	return ((t_ray){ cam->obj.position, direction });
}

#include "Element/Sphere/sphere.h"
void	hook_draw(void *param)
{
	t_world *const	world = param;

	for (int x = 0; x < world->gui.mlx->width; x++) {
		for (int y = 0; y < world->gui.mlx->height; y++) {
			t_ray ray = get_camera_ray(world->camera, world->gui.mlx->width, world->gui.mlx->height, x, y);
			t_color color = ray_color(world, &ray, 50);

			mlx_put_pixel(world->gui.image, x, world->gui.mlx->height - y - 1, ft_pixel(
				sqrt(color.x) * 255, // R
				sqrt(color.y) * 255, // G
				sqrt(color.z) * 255,  // B
				1 * 255 // A
			));	
		}
	}
}
