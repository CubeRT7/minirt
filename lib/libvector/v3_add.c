/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:58:29 by yonshin           #+#    #+#             */
/*   Updated: 2023/06/09 15:58:32 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector3	v3_add(t_vector3 v1, t_vector3 v2)
{
	return ((t_vector3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}
