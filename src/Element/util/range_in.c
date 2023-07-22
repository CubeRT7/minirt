/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:08:15 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/06 01:08:17 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element_util.h"

inline int	range_in(double t, t_range range)
{
	return (t >= range.min && t <= range.max);
}
