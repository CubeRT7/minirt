/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:59:20 by yonshin           #+#    #+#             */
/*   Updated: 2023/06/09 15:59:21 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvector.h"

t_vector3	vector3(float x, float y, float z)
{
	return ((t_vector3){x, y, z});
}