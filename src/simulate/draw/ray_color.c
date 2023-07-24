/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:27:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/25 03:10:18 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "Element/Light/light.h"
#include "Element/AmbientLight/ambient_light.h"

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
	t_vector3	brightness;
	t_hit		rec;

	if (hit(world->objs, ray, (t_range){DELTA, BIGVALUE}, &rec) == 0)
		return (v3_preset(V3_ZERO));
	brightness = _get_diffuse_light(*ray, rec, world->objs, world->lights);
	brightness = v3_add(
			v3_mul(world->ambient_light->base.color,
				world->ambient_light->obj.ratio),
			v3_mul(brightness, 1 - world->ambient_light->obj.ratio));
	return (v3_hadamard(brightness, rec.color));
}
