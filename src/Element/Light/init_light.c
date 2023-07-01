/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:10 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:24:53 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

int	init_light(t_light *self)
{
	self->color = vector3(
			self->raw.rgb.r / 255.0,
			self->raw.rgb.g / 255.0,
			self->raw.rgb.b / 255.0);
	return (EXIT_SUCCESS);
}
