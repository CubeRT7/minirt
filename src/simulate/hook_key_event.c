/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/16 11:42:09 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "simulate.h"

void	move_camera(void *param)
{
	t_world *const		world = param;
	t_element *const	camera = &(world->camera->base);
	const float			delta = 0.1;
	t_vector3			v[3];

	enum e_type {FRONT, RIGHT, NEW};
	v[FRONT] = v3_normalize(v3_hadamard(camera->axis, vector3(1, 0, 1)));
	v[RIGHT] = v3_cross(v[FRONT], world->axis);
	if (world->gui.keyboard[KEYBOARD_w])
		camera->position = v3_add(camera->position, v3_mul(v[FRONT], delta));
	if (world->gui.keyboard[KEYBOARD_s])
		camera->position = v3_sub(camera->position, v3_mul(v[FRONT], delta));
	if (world->gui.keyboard[KEYBOARD_a])
		camera->position = v3_sub(camera->position, v3_mul(v[RIGHT], delta));
	if (world->gui.keyboard[KEYBOARD_d])
		camera->position = v3_add(camera->position, v3_mul(v[RIGHT], delta));
	if (world->gui.keyboard[KEYBOARD_SPACE])
		camera->position = v3_add(camera->position, v3_mul(world->axis, delta));
	if (world->gui.keyboard[KEYBOARD_LSHIFT])
		camera->position = v3_sub(camera->position, v3_mul(world->axis, delta));
	if (world->gui.keyboard[KEYBOARD_TAB])
		world->selected = NULL;
}

void	transform_objs(void *param)
{
	t_world *const		w = param;
	t_element *const	c = &(w->camera->base);
	const t_vector3		delta = v3_mul(vector3(1, 1, 1), 0.1);

	if (w->selected && w->gui.keyboard[KEYBOARD_p])
		w->transform_type = Position;
	if (w->selected && w->gui.keyboard[KEYBOARD_t])
		w->transform_type = Rotation;
	if (w->selected && w->gui.keyboard[KEYBOARD_h])
		w->transform_type = Scaling | Height;
	if (w->selected && w->gui.keyboard[KEYBOARD_r])
		w->transform_type = Scaling | Radius;
	if (w->selected && w->gui.keyboard[KEYBOARD_x])
		w->transform_type = (w->transform_type & (Position | Rotation)) | X;
	if (w->selected && w->gui.keyboard[KEYBOARD_y])
		w->transform_type = (w->transform_type & (Position | Rotation)) | Y;
	if (w->selected && w->gui.keyboard[KEYBOARD_z])
		w->transform_type = (w->transform_type & (Position | Rotation)) | Z;
	if (w->selected && w->gui.keyboard[KEYBOARD_q])
		w->selected->func[Transform](w->selected, c, w->transform_type,
			v3_mul(delta, -1));
	if (w->selected && w->gui.keyboard[KEYBOARD_e])
		w->selected->func[Transform](w->selected, c, w->transform_type, delta);
}

int	key_press(int keycode, void *param)
{
	int				i;
	t_world *const	world = param;

	if (keycode == g_keycode[KEYBOARD_ESCAPE])
		exit(EXIT_SUCCESS);
	i = 0;
	while (i < MAX_KEYBOARD)
	{
		if (keycode == g_keycode[i])
		{
			world->gui.keyboard[i] = 1;
			return (EXIT_SUCCESS);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	key_release(int keycode, void *param)

{
	int				i;
	t_world *const	world = param;

	i = 0;
	while (i < MAX_KEYBOARD)
	{
		if (keycode == g_keycode[i])
		{
			world->gui.keyboard[i] = 0;
			return (EXIT_SUCCESS);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}
