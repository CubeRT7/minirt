/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:27:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/25 08:08:31 by minjungk         ###   ########.fr       */
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

static t_vector3	_get_diffuse_light(
	t_ray ray,
	t_hit rec,
	t_list *objs,
	t_list *lights)
{
	t_light		*light;
	t_ray		light_ray;
	t_vector3	light_direction;
	t_vector3	res;
	double		distance;
	double		dot;
	t_vector3	brightness;

	res = v3_preset(V3_ZERO);
	while (lights)
	{
		light = lights->content;
		lights = lights->next;
		light_direction = v3_sub(light->base.position, rec.p);
		distance = v3_magnitude(light_direction);
		light_ray = (t_ray){rec.p, v3_normalize(light_direction)};
		if (hit(objs, &light_ray, (t_range){DELTA, distance}, NULL))
			continue ;
		dot = v3_dot(light_ray.direction, rec.normal);
		if (dot < 0)
			continue ;
		if (close_to_zero(distance))
			distance = DELTA;
		distance = sqrt(distance);

		// diffuse_light
		brightness = v3_mul(light->base.color, dot * light->obj.ratio / distance);
		res = v3_add(res, brightness);

		// specular_light
		t_vector3 origin_direction = v3_normalize(v3_sub(ray.origin, rec.p));
		t_vector3 h = v3_normalize(v3_sub(light_direction, origin_direction));
		double v = pow(v3_dot(h, rec.normal), 100);
		brightness = _trim_bright(v3_mul(light->base.color, v));
		res = v3_add(res, brightness);
	}
	return (_trim_bright(res));
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
		rec.color = v3_hadamard(rec.color,
				_get_diffuse_light(*ray, rec, world->objs, world->lights));
	return (rec.color);
}
