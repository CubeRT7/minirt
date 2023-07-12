/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:00:10 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 08:33:54 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# define DELTA 0.001f
# define BIGVALUE 99999999.0f
# include "Element/common.h"

typedef struct s_screen
{
	struct
	{
		uint32_t	w;
		uint32_t	h;
	};
	struct
	{
		uint32_t	x;
		uint32_t	y;
	};
}	t_screen;

extern uint32_t	color_to_pixel(t_color c);
extern int		hit(t_list *objs, t_ray *ray, t_range range, t_hit *record);
extern t_ray	get_camera_ray(void *camera, t_screen screen, t_screen pos);
extern t_color	ray_color(t_ray *ray, t_list *objs, void *amb_lgt, t_list *lgt);

#endif
