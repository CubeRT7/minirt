/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:22:54 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 19:38:22 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

t_list	**get_elements(void)
{
	static t_list	*elements[MAX_ELEMENT_TYPE] = {0};

	return (elements);
}

void	clear_elements(void)
{
	int				i;
	t_list **const	elements = get_elements();

	i = 0;
	while (i < MAX_ELEMENT_TYPE)
		ft_lstclear(&elements[i++], free);
}

static int	_append(t_list **elements, t_list *node, char **cols)
{
	int								i;
	static const struct s_element	data[MAX_ELEMENT_TYPE] = {
	[AmbientLight] = {"A", sizeof(t_ambient_light), parse_ambient_light},
	[Camera] = {"C", sizeof(t_camera), parse_camera},
	[Light] = {"L", sizeof(t_light), parse_light},
	[Plane] = {"pl", sizeof(t_plane), parse_plane},
	[Sphere] = {"sp", sizeof(t_sphere), parse_sphere},
	[Cylinder] = {"cy", sizeof(t_cylinder), parse_cylinder}};

	i = 0;
	while (i < MAX_ELEMENT_TYPE)
	{
		if (!ft_strncmp(cols[0], data[i].type, ft_strlen(data[i].type) + 1))
		{
			node->content = ft_calloc(1, data[i].size);
			if (node->content && !(data[i].parse(node->content, cols + 1)))
			{
				ft_lstadd_back(&elements[i], node);
				return (EXIT_SUCCESS);
			}
			return (ft_error(__func__, __FILE__, __LINE__, 0));
		}
		++i;
	}
	return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
}

int	append_element(t_list **elements, char **cols)
{
	t_list	*node;

	if (!ft_strncmp(cols[0], "\n", 2) || !ft_strncmp(cols[0], "\r\n", 3))
		return (EXIT_SUCCESS);
	node = ft_lstnew(NULL);
	if (node == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (_append(elements, node, cols) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	ft_lstdelone(node, free);
	return (ft_error(__func__, __FILE__, __LINE__, 0));
}
