/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:31:41 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/31 19:53:04 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_BONUS_H
# define CONE_BONUS_H
# include "../Cylinder/cylinder.h"
# include "../element.h"
# include "../util/element_util.h"

typedef struct s_cone
{
	struct s_element	base;
	double				radius;
	double				height;
	t_circle			bottom;
	double				r1;
	double				r2;
	double				theta;
	double				uv_ratio;
	t_vector3			top_vertice;
}	t_cone;

extern int	hit_cone(t_cone *self, t_ray *r, t_range ra, t_hit *h);
extern int	hit_color_cone(t_cone *self, t_hit *record);
extern int	init_cone(t_cone *self);
extern int	transform_cone(
				t_cone *self,
				const t_element *camera,
				enum e_transform_type type,
				t_vector3 delta);
extern int	update_cone(t_cone *self);

#endif
