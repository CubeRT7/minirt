/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 05:35:38 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/02 20:29:41 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ambient_light.h"

int	parse_ambient_light(t_list **head, char **argv)
{
	t_list					*node;
	struct s_ambient_light	*content;

	errno = EINVAL;
	if (!argv || !argv[0] || !argv[1])
		return (EXIT_FAILURE);
	content = ft_calloc(1, sizeof(struct s_ambient_light));
	node = ft_lstnew(content);
	while (content && node)
	{
		content->ratio = ft_strtof(argv[0], NULL);
		if (parse_rgb(&content->rgb, argv[1]))
			break ;
		if (!(0.0 <= content->ratio && content->ratio <= 1.0))
			break ;
		errno = 0;
		ft_lstadd_back(head, node);
		return (EXIT_SUCCESS);
	}
	free(content);
	ft_lstdelone(node, NULL);
	return (EXIT_FAILURE);
}
