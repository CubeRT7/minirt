/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 03:59:29 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/15 12:12:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

uint32_t	color_to_pixel(t_color c)
{
	const uint8_t	r = c.x * 255;
	const uint8_t	g = c.y * 255;
	const uint8_t	b = c.z * 255;

	return (r << 16 | g << 8 | b);
}
