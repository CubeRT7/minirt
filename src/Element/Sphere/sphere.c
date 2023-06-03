/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/03 20:30:58 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

void	debug_sphere(void *param)
{
	struct s_sphere *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->coordinate.x, c->coordinate.y, c->coordinate.z);
	printf("%s: diameter[%f]\n", __func__, c->diameter);
	printf("%s: rgb[%d, %d, %d]\n", __func__, c->rgb.r, c->rgb.g, c->rgb.b);
}

int	parse_sphere(t_list **head, char **argv)
{
	t_list			*node;
	struct s_sphere	*content;

	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (ft_error(__func__, __FILE__, __LINE__));
	content = ft_calloc(1, sizeof(struct s_sphere));
	node = ft_lstnew(content);
	while (content && node)
	{
		if (parse_vector3(&content->coordinate, argv[0], Coordinate))
			break ;
		content->diameter = ft_strtof(argv[1], NULL);
		if (parse_rgb(&content->rgb, argv[2]))
			break ;
		debug_sphere(content);
		errno = 0;
		ft_lstadd_back(head, node);
		return (EXIT_SUCCESS);
	}
	free(content);
	ft_lstdelone(node, NULL);
	return (ft_error(__func__, __FILE__, __LINE__));
}
