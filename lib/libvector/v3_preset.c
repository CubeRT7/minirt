/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_preset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:32:32 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/19 14:32:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector3	v3_preset(enum e_v3_preset type)
{
	static const t_vector3	preset[V3_MAX_PRESET_IDX] = {
	[V3_ZERO] = (t_vector3){0, 0, 0},
	[V3_ONE] = (t_vector3){1, 1, 1},
	[V3_UP] = (t_vector3){0, 1, 0},
	[V3_DOWN] = (t_vector3){0, -1, 0},
	[V3_RIGHT] = (t_vector3){1, 0, 0},
	[V3_LEFT] = (t_vector3){-1, 0, 0},
	[V3_FRONT] = (t_vector3){0, 0, -1},
	[V3_BACK] = (t_vector3){0, 0, 1}};

	return (preset[type]);
}
