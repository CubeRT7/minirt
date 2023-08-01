/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:00 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/02 02:08:17 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

extern int	update_camera(t_camera *self);
extern int	serialize_camera(int fd, t_element *element);

int	init_camera(t_camera *self)
{
	self->base.func[Update] = update_camera;
	self->base.func[Serialize] = serialize_camera;
	return (EXIT_SUCCESS);
}
