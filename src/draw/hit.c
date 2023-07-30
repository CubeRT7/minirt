/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 04:11:34 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 19:51:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	_hit(t_list *objs, t_ray *ray, t_range range, t_hit *record)
{
	t_hit		tmp_rec;
	int			hit_anything;
	t_element	*elem;

	hit_anything = 0;
	while (objs)
	{
		elem = objs->content;
		if (elem->func[Hit](elem, ray, range, &tmp_rec))
		{
			hit_anything = 1;
			range.max = tmp_rec.t;
			tmp_rec.elem = (void *)elem;
			if (record != NULL)
				*record = tmp_rec;
		}
		objs = objs->next;
	}
	return (hit_anything);
}

int	hit(t_list *objs, t_ray *ray, t_range range, t_hit *record)
{
	const int	hit_anything = _hit(objs, ray, range, record);
	t_element	*elem;

	if (hit_anything && record != NULL)
	{
		elem = (t_element *)(record->elem);
		if (hit_anything && record != NULL && elem->func[HitColor])
			elem->func[HitColor](elem, record);
	}
	return (hit_anything);
}
