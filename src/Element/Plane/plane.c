/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:04:44 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/03 22:44:09 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

t_func	plane(enum e_element_func func)
{
	static const t_func	functions[MAX_ELEMENT_TYPE] = {
	[Init] = init_plane,
	[Hit] = hit_plane,
	[Debug] = debug_plane};

	return (functions[func]);
}
