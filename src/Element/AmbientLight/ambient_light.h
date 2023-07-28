/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/28 20:57:09 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H
# include "../element.h"
# include "../util/element_util.h"

typedef struct s_ambient_light
{
	struct s_element	base;
	double				ratio;
}	t_ambient_light;

extern int		init_ambient_light(t_ambient_light *self);

#endif 
