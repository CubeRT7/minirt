/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:27:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 09:16:45 by yonshin          ###   ########.fr       */
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

static t_vector3	_get_diffuse_light(t_hit rec, t_list *objs, t_list *lights)
{
	t_light		*light;
	t_ray		light_ray;
	t_vector3	direction;
	t_vector3	res;
	float		d;

	res = v3_preset(V3_ZERO);
	while (lights)
	{
		light = lights->content;
		lights = lights->next;
		direction = v3_sub(light->base.position, rec.p);
		d = v3_magnitude(direction);
		light_ray = (t_ray){rec.p, v3_normalize(direction)};
		if (hit(objs, &light_ray, (t_range){DELTA, d}, NULL))
			continue ;
		d = v3_dot(light_ray.direction, rec.normal);
		if (d < 0)
			continue ;
		res = v3_add(res, v3_mul(vector3(d, d, d), light->obj.ratio));
	}
	return (_trim_bright(res));
}

t_color	ray_color(t_ray *ray, t_list *objs, void *ambient_light, t_list *lights)
{
	const t_ambient_light	*a_lgt = ambient_light;
	t_vector3				brightness;
	t_hit					rec;

	if (hit(objs, ray, (t_range){DELTA, BIGVALUE}, &rec))
	{
		brightness = _get_diffuse_light(rec, objs, lights);
		brightness = v3_add(
				v3_mul(a_lgt->base.color, a_lgt->obj.ratio),
				v3_mul(brightness, 1 - a_lgt->obj.ratio));
		return (v3_hadamard(brightness, rec.color));
	}
	return (v3_preset(V3_ZERO));
}
