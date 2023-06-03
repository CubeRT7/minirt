/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:37:19 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/03 20:29:26 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"

void	debug_light(void *param)
{
	struct s_light *const	c = param;

	if (c == NULL || DEBUG == 0)
		return ;
	printf("%s: coordinate[%f, %f, %f]\n", __func__,
		c->coordinate.x, c->coordinate.y, c->coordinate.z);
	printf("%s: ratio[%f]\n", __func__, c->ratio);
	printf("%s: rgb[%d, %d, %d]\n", __func__, c->rgb.r, c->rgb.g, c->rgb.b);
}

int	parse_light(t_list **head, char **argv)
{
	t_list			*node;
	struct s_light	*content;

	errno = EINVAL;
	if (!argv || !argv[0] || !argv[1])
		return (ft_error(__func__, __FILE__, __LINE__));
	content = ft_calloc(1, sizeof(struct s_light));
	node = ft_lstnew(content);
	while (content && node)
	{
		if (parse_vector3(&content->coordinate, argv[0], Coordinate))
			break ;
		content->ratio = ft_strtof(argv[1], NULL);
		if (!(0.0 <= content->ratio && content->ratio <= 1.0))
			break ;
		if (argv[2] && parse_rgb(&content->rgb, argv[2]))
			break ;
		debug_light(content);
		errno = 0;
		ft_lstadd_back(head, node);
		return (EXIT_SUCCESS);
	}
	free(content);
	ft_lstdelone(node, NULL);
	return (ft_error(__func__, __FILE__, __LINE__));
}
