/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:38:22 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/03 20:29:42 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

void	debug_plane(void *param)
{
	struct s_plane *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->coordinate.x, c->coordinate.y, c->coordinate.z);
	printf("%s: axis[%f, %f, %f]\n", __func__, c->axis.x, c->axis.y, c->axis.z);
	printf("%s: rgb[%d, %d, %d]\n", __func__, c->rgb.r, c->rgb.g, c->rgb.b);
}

int	parse_plane(t_list **head, char **argv)
{
	t_list			*node;
	struct s_plane	*content;

	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (ft_error(__func__, __FILE__, __LINE__));
	content = ft_calloc(1, sizeof(struct s_plane));
	node = ft_lstnew(content);
	while (content && node)
	{
		if (parse_vector3(&content->coordinate, argv[0], Coordinate))
			break ;
		if (parse_vector3(&content->axis, argv[1], Vector))
			break ;
		if (parse_rgb(&content->rgb, argv[2]))
			break ;
		debug_plane(content);
		errno = 0;
		ft_lstadd_back(head, node);
		return (EXIT_SUCCESS);
	}
	free(content);
	ft_lstdelone(node, NULL);
	return (ft_error(__func__, __FILE__, __LINE__));
}
