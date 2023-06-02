/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:44 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/02 19:32:24 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

int	parse_sphere(t_list **head, char **argv)
{
	t_list			*node;
	struct s_sphere	*content;

	errno = EINVAL;
	if (!argv || !argv[0] || !argv[1] || !argv[2])
		return (EXIT_FAILURE);
	content = ft_calloc(1, sizeof(struct s_sphere));
	node = ft_lstnew(content);
	while (content && node)
	{
		if (parse_vector3(&content->coordinate, argv[0], Coordinate))
			break ;
		content->diameter = ft_strtof(argv[1], NULL);
		if (parse_rgb(&content->rgb, argv[2]))
			break ;
		errno = 0;
		ft_lstadd_back(head, node);
		return (EXIT_SUCCESS);
	}
	free(content);
	ft_lstdelone(node, NULL);
	return (EXIT_FAILURE);
}
