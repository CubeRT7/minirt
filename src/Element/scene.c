/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:22:54 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/04 23:46:33 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_list	**get_scene(void)
{
	static t_list	*scene[MAX_SCENE] = {0};

	return (scene);
}

void	clear_scene(void)
{
	int				i;
	t_list **const	scene = get_scene();

	i = 0;
	while (i < MAX_SCENE)
		ft_lstclear(&scene[i++], free);
}
