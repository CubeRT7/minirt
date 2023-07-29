/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_cylinder_bumpmap_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:47:50 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 13:01:01 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "Element/util/element_util_bonus.h"

t_color	hit_color_cylinder_bumpmap(t_cylinder *self, t_hit *record)
{
	(void)self;
	(void)record;
	return (self->base.color);
}
