/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/15 12:56:48 by minjungk         ###   ########.fr       */
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
	if (world->gui.keyboard[KEYBOARD_W])
		camera->position = v3_add(camera->position, v3_mul(v[FRONT], delta));
	if (world->gui.keyboard[KEYBOARD_S])
		camera->position = v3_sub(camera->position, v3_mul(v[FRONT], delta));
	if (world->gui.keyboard[KEYBOARD_A])
		camera->position = v3_sub(camera->position, v3_mul(v[RIGHT], delta));
	if (world->gui.keyboard[KEYBOARD_D])
		camera->position = v3_add(camera->position, v3_mul(v[RIGHT], delta));
	if (world->gui.keyboard[KEYBOARD_SPACE])
		camera->position = v3_add(camera->position, v3_mul(world->axis, delta));
	if (world->gui.keyboard[KEYBOARD_LSHIFT])
		camera->position = v3_sub(camera->position, v3_mul(world->axis, delta));
	if (world->gui.keyboard[KEYBOARD_TAB])
		world->selected = NULL;

	if (world->selected && world->gui.keyboard[KEYBOARD_P])
		world->transform_type = Position;
	if (world->selected && world->gui.keyboard[KEYBOARD_T])
		world->transform_type = Rotation;
	if (world->selected && world->gui.keyboard[KEYBOARD_H])
		world->transform_type = Scaling | Height;
	if (world->selected && world->gui.keyboard[KEYBOARD_R])
		world->transform_type = Scaling | Radius;
	if (world->selected && world->gui.keyboard[KEYBOARD_X])
		world->transform_type = (world->transform_type & (Position | Rotation)) | X;
	if (world->selected && world->gui.keyboard[KEYBOARD_Y])
		world->transform_type = (world->transform_type & (Position | Rotation)) | Y;
	if (world->selected && world->gui.keyboard[KEYBOARD_Z])
		world->transform_type = (world->transform_type & (Position | Rotation)) | Z;
	if (world->selected && world->gui.keyboard[KEYBOARD_Q])
		world->selected->func[Transform](world->selected, camera, world->transform_type,  v3_mul(vector3(1, 1, 1), -delta));
	if (world->selected && world->gui.keyboard[KEYBOARD_E])
		world->selected->func[Transform](world->selected, camera, world->transform_type, v3_mul(vector3(1, 1, 1), delta));
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
