/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:00:10 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 18:31:10 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "Element/element.h"
# include "miniRT.h"

extern t_color	ray_color(t_world *world, t_vector3 pos);
extern void		render_main_frame(t_world *world);

#endif
