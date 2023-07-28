/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:27:05 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 05:00:08 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"
#include "Element/Light/light.h"
#include "Element/AmbientLight/ambient_light.h"

static t_vector3	_trim_bright(t_vector3 bright)
{
	bright.x = fmin(1, bright.x);
	bright.y = fmin(1, bright.y);
	bright.z = fmin(1, bright.z);
	return (bright);
}

static double	_calc_specular(t_hit rec, t_ray view, t_ray to_light)
{
	t_vector3	half_direction;
	t_vector3	view_direction;

	view_direction = v3_normalize(v3_sub(view.origin, rec.p));
	half_direction = v3_normalize(v3_add(to_light.direction, view_direction));
	return (pow(fmax(0, v3_dot(half_direction, rec.normal)), 100));
}

static t_color	_bright(t_ray ray, t_world *world, t_hit rec, t_light *light)
{
	t_ray	to_light;
	t_range	distance;
	t_color	ambient;
	double	brightness;

	to_light = (t_ray){rec.p, v3_sub(light->base.position, rec.p)};
	distance = (t_range){DELTA, v3_magnitude(to_light.direction)};
	to_light.direction = v3_normalize(to_light.direction);
	if (hit(world->objs, &to_light, distance, NULL))
		return (v3_preset(V3_ZERO));
	ambient = v3_preset(V3_ZERO);
	if (world->render_mode & RENDER_AMBIENT)
		ambient = v3_mul(
				world->ambient_light->base.color,
				world->ambient_light->ratio);
	brightness = 0;
	if (world->render_mode & RENDER_DIFFUSE)
		brightness = fmax(0, v3_dot(to_light.direction, rec.normal));
	if (world->render_mode & RENDER_SPECULAR)
		brightness = _calc_specular(rec, ray, to_light);
	return (_trim_bright(v3_add(ambient,
				v3_mul(light->base.color, light->ratio * brightness))));
}

t_color	ray_color(t_ray *ray, t_world *world)
{
	t_hit	rec;
	t_list	*curr;
	t_color	brightness;
	t_color	brightness_sum;

	if (hit(world->objs, ray, (t_range){DELTA, BIGVALUE}, &rec) == 0)
		return (v3_preset(V3_ZERO));
	brightness_sum = v3_preset(V3_ZERO);
	curr = world->lights;
	while (curr)
	{
		brightness = _bright(*ray, world, rec, curr->content);
		brightness_sum = v3_add(brightness_sum, brightness);
		curr = curr->next;
	}
	brightness_sum = _trim_bright(brightness_sum);
	if ((world->render_mode & RENDER_ORIGINAL) == 0)
		return (brightness_sum);
	return (v3_hadamard(rec.color, brightness_sum));
}
