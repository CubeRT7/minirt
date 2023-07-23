/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_draw_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:15:47 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/20 17:01:44 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate/util/simulate_util.h"

void	move_camera(void *param)
{
	t_world *const		world = param;
	t_element *const	camera = &(world->camera->base);
	const double		delta = 0.1;
	t_vector3			v[3];

	enum e_type {FRONT, RIGHT, NEW};
	v[FRONT] = v3_normalize(v3_hadamard(camera->front, vector3(1, 0, 1)));
	v[RIGHT] = v3_cross(v[FRONT], world->axis);
	if (world->device.keyboard[KEYBOARD_w])
		camera->position = v3_add(camera->position, v3_mul(v[FRONT], delta));
	if (world->device.keyboard[KEYBOARD_s])
		camera->position = v3_sub(camera->position, v3_mul(v[FRONT], delta));
	if (world->device.keyboard[KEYBOARD_a])
		camera->position = v3_sub(camera->position, v3_mul(v[RIGHT], delta));
	if (world->device.keyboard[KEYBOARD_d])
		camera->position = v3_add(camera->position, v3_mul(v[RIGHT], delta));
	if (world->device.keyboard[KEYBOARD_SPACE])
		camera->position = v3_add(camera->position, v3_mul(world->axis, delta));
	if (world->device.keyboard[KEYBOARD_LSHIFT])
		camera->position = v3_sub(camera->position, v3_mul(world->axis, delta));
	if (world->device.keyboard[KEYBOARD_TAB])
		world->selected = NULL;
}

void	transform_objs(void *param)
{
	t_world *const		w = param;

	if (w->selected && w->device.keyboard[KEYBOARD_p])
		w->transform_type = Position;
	if (w->selected && w->device.keyboard[KEYBOARD_t])
		w->transform_type = Rotation;
	if (w->selected && w->device.keyboard[KEYBOARD_h])
		w->transform_type = Scaling | Height;
	if (w->selected && w->device.keyboard[KEYBOARD_r])
		w->transform_type = Scaling | Radius;
	if (w->selected && w->device.keyboard[KEYBOARD_x])
		w->transform_type = (w->transform_type & (Position | Rotation)) | X;
	if (w->selected && w->device.keyboard[KEYBOARD_y])
		w->transform_type = (w->transform_type & (Position | Rotation)) | Y;
	if (w->selected && w->device.keyboard[KEYBOARD_z])
		w->transform_type = (w->transform_type & (Position | Rotation)) | Z;
}

void	rotate_camera(void *param)
{
	t_world *const		world = param;
	t_camera *const		camera = world->camera;
	t_device *const		device = &world->device;
	t_vector3			v[3];
	double				angle;

	enum e_type {RIGHT, NEW, MOVE};
	if (device->mouse.action[MOUSE_BUTTON_RIGHT] == MOUSE_IDLE)
		return ;
	v[MOVE] = v3_sub(device->mouse.prev, device->mouse.curr);
	rotate_element(&(camera->base), world->axis, v[MOVE].x / device->size.x);
	v[RIGHT] = vector3(camera->base.right.x, 0, camera->base.right.z);
	v[NEW] = v3_rotate_axis(camera->base.front, v[RIGHT],
			v[MOVE].y / device->size.y);
	angle = v3_dot(v3_normalize(v3_cross(v[NEW], world->axis)), v[RIGHT]);
	if (angle <= 0)
		return ;
	rotate_element(&(camera->base), v[RIGHT], v[MOVE].y / device->size.y);
}

void	transform_objs_with_mouse(void *param)
{
	t_world *const		w = param;
	t_element *const	c = &(w->camera->base);
	t_vector3			delta;

	if (w->selected == NULL || !(w->transform_type & 0xf00))
		return ;
	delta = v3_sub(w->device.mouse.curr, w->device.mouse.prev);
	delta.y = -delta.y;
	delta.z = delta.x - delta.y;
	delta = v3_mul(delta, 0.01);
	w->selected->func[Transform](w->selected, c, w->transform_type, delta);
}

int	hook_draw_setting(void *param)
{
	t_world *const		world = param;
	t_device *const		device = &world->device;
	const t_vector3		point_in_world = vector3(
			device->mouse.curr.x,
			device->size.y - device->mouse.curr.y,
			0);

	world->camera->obj.ratio = (double)device->size.y / device->size.x;
	if (device->mouse.action[MOUSE_BUTTON_LEFT] == MOUSE_PRESS)
		world->selected = select_element(world, point_in_world);
	if (device->keyboard[KEYBOARD_RETURN] && world->lights)
		world->selected = (t_element *)(world->lights->content);
	move_camera(world);
	rotate_camera(world);
	transform_objs(world);
	world_iter(world, Update);
	return (EXIT_SUCCESS);
}
