/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:00 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 19:42:04 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	init_camera(t_camera *self)
{
	self->base.func[Update] = update_camera;
	return (EXIT_SUCCESS);
}
