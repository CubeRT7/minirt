/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:11:34 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/12 05:57:37 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulate_util.h"

int	hit(t_list *objs, t_ray *ray, t_range range, t_hit *record)
{
	t_hit			tmp_rec;
	double			max_len;
	int				hit_anything;
	t_element		*elem;

	hit_anything = 0;
	max_len = range.max;
	while (objs)
	{
		elem = objs->content;
		if (elem->func[Hit](elem, ray, (t_range){range.min, max_len}, &tmp_rec))
		{
			hit_anything = 1;
			max_len = tmp_rec.t;
			tmp_rec.elem = elem;
			if (record != NULL)
				*record = tmp_rec;
		}
		objs = objs->next;
	}
	if (hit_anything && record != NULL && record->elem->func[HitColor])
		record->elem->func[HitColor](record->elem, record);
	return (hit_anything);
}
