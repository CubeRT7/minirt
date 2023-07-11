/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/08 17:25:50 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "simulate/util/simulate_util.h"
#define DELTA 0.001f
#define BIGVALUE 99999999.0f

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

t_color	back_ground_color(t_ray ray)
{
	const float	t = (ray.direction.y + 1) * 0.5f;

	return (v3_add(vector3(1 - t, 1 - t, 1 - t),
			v3_mul(vector3(0.5, 0.7, 1.0), t)));
}

int	hit(t_world *world, t_ray *ray, t_range range, t_hit *record)
{
	t_hit			temp_rec;
	const t_list	*next = world->objs;
	float			closest_so_far;
	int				hit_anything;
	t_element		*elem;

	hit_anything = 0;
	closest_so_far = range.max;
	while (next)
	{
		elem = next->content;
		if (elem->func[Hit](elem, ray, (t_range){range.min, closest_so_far}, &temp_rec))
		{
			hit_anything = 1;
			closest_so_far = temp_rec.t;
			if (record != NULL)
			{
				temp_rec.color = elem->color;
				*record = temp_rec;
			}
		}
		next = next->next;
	}
	return (hit_anything);
}

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
	if (hit(world, ray, (t_range){DELTA, BIGVALUE}, &rec))
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
			if (hit(world, &light_ray, (t_range){ DELTA, length }, NULL))
				continue;
			dot1 = v3_dot_prod(light_ray.direction, rec.normal);
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

t_element	*find(t_list *list, enum e_element type)
{
	while (list)
	{
		if (((t_element *)(list->content))->type == type)
			return (list->content);
		list = list->next;
	}
	return (NULL);
}

#include "Element/Camera/camera.h"
static t_ray	get_camera_ray(void *camera, int width, int height, int x, int y)
{
	const t_camera	*cam = camera;
	const float		aspect_ratio = (float)height / width;
	const float		viewport_width = 2.0f;
	const float		viewport_height =  aspect_ratio * viewport_width;
	const float		fov_half = cam->obj.fov_radian * 0.5f;
	if (sin(fov_half) == 0)
		return ((t_ray){ cam->base.position, cam->base.axis });
	float		focal_length = cos(fov_half) / sin(fov_half);
	t_vector3	horizontal = vector3(viewport_width, 0, 0);
	t_vector3	vertical = vector3(0, viewport_height, 0);
	t_point		lower_left_corner = vector3(0, 0, 0);
	lower_left_corner = v3_sub(lower_left_corner, v3_mul(horizontal, 0.5f));
	lower_left_corner = v3_sub(lower_left_corner, v3_mul(vertical, 0.5f));
	lower_left_corner = v3_sub(lower_left_corner, vector3(0, 0, focal_length));

	float		u = (float)x / width;
	float		v = (float)y / height;
	t_vector3	direction = lower_left_corner;
	direction = v3_add(direction, v3_mul(horizontal, u));
	direction = v3_add(direction, v3_mul(vertical, v));
	direction = v3_normalize(direction);
	t_vector3 front = v3_normalize(vector3(cam->base.axis.x, 0, cam->base.axis.z));
	t_vector3 right = v3_normalize(v3_cross_prod(front, vector3(0, 1, 0)));
	float h_angle = acosf(v3_dot_prod(vector3(0, 0, -1), front) * 0.99999f) * (front.x < 0 ? 1 : -1);
	float v_angle = acosf(v3_dot_prod(front, cam->base.axis) * 0.99999f) * (cam->base.axis.y < 0 ? -1 : 1);
	direction = v3_rotate_axis(direction, vector3(0, 1, 0), h_angle);
	direction = v3_rotate_axis(direction, right, v_angle);
	return ((t_ray){cam->base.position, direction});
}

void	hook_draw(void *param)
{
	t_world *const	world = param;
	int				x;
	int				y;
	t_ray			ray;
	t_color			color;

	world_iter(world, Update);
	rotate_camera(world);
	x = 0;
	while (x < world->gui.mlx->width)
	{
		y = 0;
		while (y < world->gui.mlx->height)
		{
			ray = get_camera_ray(world->camera,
				world->gui.mlx->width,
				world->gui.mlx->height, x, y);
			color = ray_color(world, &ray, 50);
			mlx_put_pixel(world->gui.image, x, world->gui.mlx->height - y - 1,
				ft_pixel(sqrt(color.x) * 255, sqrt(color.y) * 255, sqrt(color.z) * 255, 255));
			++y;
		}
		++x;
	}
}
