/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:27:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/26 17:36:19 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "Element/Light/light.h"
#include "Element/AmbientLight/ambient_light.h"

t_color	alpha_blend(t_vector3 old, t_vector3 new, double new_alpha)
{
	t_color			color;
	const double	old_alpha = 1 - new_alpha;

	if (old_alpha <= 0)
		return (new);
	if (new_alpha <= 0)
		return (old);
	color.x = old.x * old_alpha + new.x * new_alpha;
	color.y = old.y * old_alpha + new.y * new_alpha;
	color.z = old.z * old_alpha + new.z * new_alpha;
	return (color);
}

static t_vector3	_trim_bright(t_vector3 bright)
{
	if (bright.x > 1)
		bright.x = 1;
	if (bright.y > 1)
		bright.y = 1;
	if (bright.z > 1)
		bright.z = 1;
	return (bright);
}

static t_vector3	_get_light(
	t_ray ray,
	t_hit rec,
	t_world *world,
	t_light *light)
{
	t_ray		to_light;
	double		light_distance;
	t_vector3	light_direction;
	t_vector3	half_direction;
	t_vector3	view_direction;
	double		diffuse;
	t_color		diffuse_color;
	double		specular;
	t_color		specular_color;

	light_direction = v3_sub(light->base.position, rec.p);
	light_distance = v3_magnitude(light_direction);
	light_direction = v3_normalize(light_direction);
	to_light = (t_ray){rec.p, light_direction};
	if (hit(world->objs, &to_light, (t_range){DELTA, light_distance}, NULL))
		return (v3_preset(V3_ZERO));
	diffuse = 0;
	if (world->render_mode & RENDER_DIFFUSE)
		diffuse = fmax(0, v3_dot(light_direction, rec.normal));
	diffuse_color = (v3_mul(light->base.color, light->obj.ratio * diffuse));
	specular = 0;
	if (world->render_mode & RENDER_SPECULAR)
	{
		view_direction = v3_normalize(v3_sub(ray.origin, rec.p));
		half_direction = v3_normalize(v3_add(light_direction, view_direction));
		specular = pow(fmax(0, v3_dot(half_direction, rec.normal)), 100);
	}
	specular_color = (v3_mul(light->base.color, light->obj.ratio * specular));
	return (v3_add(diffuse_color, specular_color));
}

static t_color	_get_lights(t_ray *ray, t_world *world, t_hit *rec)
{
	t_list	*curr;
	t_color	brightness;
	t_color	brightness_sum;
	int		brightness_cnt;

	brightness_cnt = 0;
	brightness_sum = v3_preset(V3_ZERO);
	curr = world->lights;
	while (curr)
	{
		// TODO: empty light skip and none counting
		brightness = (_get_light(*ray, *rec, world, curr->content));
		brightness_sum = v3_add(brightness_sum, brightness);
		brightness_cnt++;
		curr = curr->next;
	}
	return (v3_mul(brightness_sum, 1.0 / brightness_cnt));
}

t_color	ray_color(t_ray *ray, t_world *world)
{
	t_hit	rec;

	if (hit(world->objs, ray, (t_range){DELTA, BIGVALUE}, &rec) == 0)
		return (v3_preset(V3_ZERO));
	rec.color = v3_preset(V3_ZERO);
	if (world->render_mode & RENDER_AMBIENT)
		rec.color = v3_mul(
				world->ambient_light->base.color,
				world->ambient_light->obj.ratio);
	if (world->render_mode & (RENDER_DIFFUSE | RENDER_SPECULAR))
		rec.color = _trim_bright(v3_add(rec.color, _get_lights(ray, world, &rec)));
	if ((world->render_mode & RENDER_ORIGINAL) == 0)
		return (rec.color);
	return (alpha_blend(rec.color, rec.elem->color, 0.5));
}
