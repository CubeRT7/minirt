/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:00:10 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 01:36:46 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "Element/common.h"
# include "simulate.h"

extern t_color	ray_color(t_ray *ray, t_world *world);
extern void		render_main_frame(t_world *world);

#endif
