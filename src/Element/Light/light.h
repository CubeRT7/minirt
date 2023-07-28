/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 20:57:45 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H
# include "../element.h"
# include "../util/element_util.h"

typedef struct s_light
{
	struct s_element	base;
	double				ratio;
}	t_light;

extern int		init_light(t_light *self);

#endif 
