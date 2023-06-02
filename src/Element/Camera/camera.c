/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:36:34 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/02 19:25:11 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

int	parse_camera(t_list **head, char **argv)
{
	t_list			*node;
	struct s_camera	*content;

	errno = EINVAL;
	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (EXIT_FAILURE);
	content = ft_calloc(1, sizeof(struct s_camera));
	node = ft_lstnew(content);
	while (content && node)
	{
		if (parse_vector3(&content->coordinate, argv[0], Coordinate))
			break ;
		if (parse_vector3(&content->axis, argv[1], Vector))
			break ;
		content->fov = ft_strtof(argv[2], NULL);
		if (!(0.0 <= content->fov && content->fov <= 180.0))
			break ;
		errno = 0;
		ft_lstadd_back(head, node);
		return (EXIT_SUCCESS);
	}
	free(content);
	ft_lstdelone(node, NULL);
	return (EXIT_FAILURE);
}
