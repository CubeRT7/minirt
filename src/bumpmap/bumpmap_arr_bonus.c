/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bumpmap_arr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:11:17 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/30 16:19:35 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bumpmap_bonus.h"

t_bump_map	**bumpmap_arr(void)
{
	static t_bump_map	*bumpmap = NULL;

	return (&bumpmap);
}
