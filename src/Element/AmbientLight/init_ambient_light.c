/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambient_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 02:12:26 by yonshin           #+#    #+#             */
/*   Updated: 2023/08/02 02:08:12 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient_light.h"

extern int	serialize_ambient_light(int fd, t_element *element);

int	init_ambient_light(t_ambient_light *self)
{
	self->base.func[Serialize] = serialize_ambient_light;
	return (EXIT_SUCCESS);
}
