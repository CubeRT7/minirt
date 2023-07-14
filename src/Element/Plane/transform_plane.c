/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 08:48:39 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/14 08:48:40 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

int	transform_plane(
	t_plane *self,
	const t_element *camera,
	enum e_transform_type type,
	t_vector3 delta)
{
	(void)self;
	(void)camera;
	(void)type;
	(void)delta;
	return (EXIT_SUCCESS);
}
