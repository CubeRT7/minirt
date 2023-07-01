/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:37:59 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:03:45 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "Element/Sphere/sphere.h"

void	hook_key_event(void *param)
{
	t_world *const	world = param;

	if (mlx_is_key_down(world->gui.mlx, MLX_KEY_ESCAPE))
		mlx_close_window(world->gui.mlx);
}
