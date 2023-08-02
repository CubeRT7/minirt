/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 04:01:36 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/04 05:32:25 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	clean_rt(struct s_rt_file *rt)
{
	if (rt == NULL)
		return ;
	ft_lstclear(&rt->ambient_light, free);
	ft_lstclear(&rt->camera, free);
	ft_lstclear(&rt->lights, free);
	ft_lstclear(&rt->objs, free);
}
