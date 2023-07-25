/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:27:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/25 10:54:56 by minjungk         ###   ########.fr       */
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
	t_list *objs,
	t_light *light)
{
	t_ray		light_ray;
	t_vector3	light_direction;
	t_vector3	half_direction;
	t_vector3	view_direction;
	double		distance;
	double		diffuse;
	double		specular;

	light_direction = v3_sub(light->base.position, rec.p);
	distance = v3_magnitude(light_direction);
	light_ray = (t_ray){rec.p, v3_normalize(light_direction)};
	if (hit(objs, &light_ray, (t_range){DELTA, distance}, NULL))
		return (v3_preset(V3_ZERO));
	// diffuse_light
	diffuse = v3_dot(light_ray.direction, rec.normal);
	if (diffuse < 0)
		return (v3_preset(V3_ZERO));
	if (close_to_zero(distance))
		distance = DELTA;
	distance = sqrt(distance);
	// specular_light
	view_direction = v3_normalize(v3_sub(ray.origin, rec.p));
	half_direction = v3_normalize(v3_sub(light_direction, view_direction));
	specular = pow(v3_dot(half_direction, rec.normal), 100);
	return (_trim_bright(v3_mul(light->base.color,
				(diffuse + specular) * light->obj.ratio / distance)));
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
		brightness = (_get_light(*ray, *rec, world->objs, curr->content));
		brightness_sum = v3_add(brightness_sum, brightness);
		brightness_cnt++;
		curr = curr->next;
	}
	brightness = _trim_bright(v3_mul(brightness_sum, 1.0 / brightness_cnt));
	return (v3_hadamard(rec->color, brightness));
}

t_color	ray_color(t_ray *ray, t_world *world)
{
	t_hit	rec;

	if (hit(world->objs, ray, (t_range){DELTA, BIGVALUE}, &rec) == 0)
		return (v3_preset(V3_ZERO));
	if ((world->render_mode & RENDER_ORIGINAL) == 0)
		rec.color = v3_preset(V3_ZERO);
	if (world->render_mode & RENDER_AMBIENT)
		rec.color = alpha_blend(rec.color,
				world->ambient_light->base.color,
				world->ambient_light->obj.ratio);
	if (world->render_mode & (RENDER_DIFFUSE | RENDER_SPECULAR))
		rec.color = _get_lights(ray, world, &rec);
	return (rec.color);
}
