/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:27:39 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/02 02:27:40 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phong.h"

extern int	phong_scatter(t_ray *ray, t_hit *hit, t_color *color)
{
	(void)ray;
	(void)hit;
	*color = hit->color;
	return (0);
}
