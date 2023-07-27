/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/26 06:55:20 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

int	hit_color_plane(t_plane *self, t_hit *record)
{
	record->color = self->base.color;
	return (EXIT_SUCCESS);
}
