/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:10:36 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/20 08:24:40 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "simulate.h"

int	button_press(int button, int x, int y, void *param)
{
	t_world *const	world = param;

	if (x < 0 || x >= world->viewport.screen.x)
		return (EXIT_SUCCESS);
	if (y < 0 || y >= world->viewport.screen.y)
		return (EXIT_SUCCESS);
	if (world->viewport.mouse.action[button] == MOUSE_PRESS)
		world->viewport.mouse.action[button] = MOUSE_REPEAT;
	else
		world->viewport.mouse.action[button] = MOUSE_PRESS;
	return (EXIT_SUCCESS);
}

int	button_release(int button, int x, int y, void *param)
{
	t_world *const	world = param;

	(void)x;
	(void)y;
	world->viewport.mouse.action[button] = MOUSE_IDLE;
	return (EXIT_SUCCESS);
}

void	rotate_camera(void *param)
{
	t_world *const		world = param;
	t_camera *const		camera = world->camera;
	t_viewport *const	viewport = &world->viewport;
	t_vector3			v[4];
	double				angle;

	enum e_type {FRONT, RIGHT, NEW, MOVE};
	if (viewport->mouse.action[MOUSE_BUTTON_RIGHT] == MOUSE_IDLE)
		return ;
	v[MOVE] = v3_sub(viewport->mouse.prev, viewport->mouse.curr);
	v[FRONT] = v3_normalize(v3_hadamard(camera->base.axis, vector3(1, 0, 1)));
	v[RIGHT] = v3_normalize(v3_cross(v[FRONT], world->axis));
	camera->base.axis = v3_rotate_axis(camera->base.axis, world->axis,
			v[MOVE].x / viewport->screen.x);
	v[NEW] = v3_rotate_axis(camera->base.axis, v[RIGHT],
			v[MOVE].y / viewport->screen.y);
	angle = v3_dot(v3_normalize(v3_cross(v[NEW], world->axis)), v[RIGHT]);
	if (angle > 0)
		camera->base.axis = v[NEW];
}

void	transform_objs_with_mouse(void *param)
{
	t_world *const		w = param;
	t_element *const	c = &(w->camera->base);
	t_vector3			delta;

	if (w->selected == NULL || !(w->transform_type & 0xf00))
		return ;
	delta = v3_sub(w->viewport.mouse.curr, w->viewport.mouse.prev);
	delta.y = -delta.y;
	delta.z = delta.x - delta.y;
	delta = v3_mul(delta, 0.01);
	w->selected->func[Transform](w->selected, c, w->transform_type, delta);
}
