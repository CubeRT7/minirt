/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 00:28:06 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/17 16:53:52 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_util.h"

void	rotate_element(t_element *elem, t_vector3 axis, float delta)
{
	elem->front = v3_normalize(v3_rotate_axis(elem->front, axis, delta));
	elem->up = v3_normalize(v3_rotate_axis(elem->up, axis, delta));
	elem->right = v3_normalize(v3_rotate_axis(elem->right, axis, delta));
}
