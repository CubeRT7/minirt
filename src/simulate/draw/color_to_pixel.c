/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:59:29 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 04:01:13 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

uint32_t	color_to_pixel(t_color c)
{
	const uint32_t	r = c.x * 255;
	const uint32_t	g = c.y * 255;
	const uint32_t	b = c.z * 255;

	return (r << 24 | g << 16 | b << 8 | 0xFF);
}
