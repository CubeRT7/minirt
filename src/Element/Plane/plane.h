/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 20:57:57 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H
# include "../element.h"
# include "../util/element_util.h"

typedef struct s_plane
{
	struct s_element	base;
}	t_plane;

extern int	hit_plane(t_plane *self, t_ray *r, t_range ra, t_hit *h);
extern int	hit_color_plane(t_plane *self, t_hit *record);
extern int	init_plane(t_plane *self);

#endif 
