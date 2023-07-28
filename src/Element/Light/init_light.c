/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:42:10 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 19:57:13 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

int	init_light(t_light *self)
{
	self->base.func[Transform] = transform_element;
	return (EXIT_SUCCESS);
}
