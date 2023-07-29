/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_color_cylinder_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:55:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/29 12:48:53 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "Element/util/element_util_bonus.h"

t_color	hit_color_cylinder_checker(t_cylinder *self, t_hit *record);
t_color	hit_color_cylinder_bumpmap(t_cylinder *self, t_hit *record);

int	hit_color_cylinder(t_cylinder *self, t_hit *record)
{
	record->color = hit_color_cylinder_checker(self, record);
	if (1)
		record->color = hit_color_cylinder_bumpmap(self, record);
	return (EXIT_SUCCESS);
}
