/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:22:54 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/05 06:00:18 by minjungk         ###   ########.fr       */
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

static int	_append(t_list **scene, t_list *node, char **cols)
{
	int								i;
	static const struct s_element	data[MAX_SCENE] = {
	[AmbientLight] = {"A", sizeof(struct s_ambient_light), parse_ambient_light},
	[Camera] = {"C", sizeof(struct s_camera), parse_camera},
	[Light] = {"L", sizeof(struct s_light), parse_light},
	[Plane] = {"pl", sizeof(struct s_plane), parse_plane},
	[Sphere] = {"sp", sizeof(struct s_sphere), parse_sphere},
	[Cylinder] = {"cy", sizeof(struct s_cylinder), parse_cylinder}};

	i = 0;
	while (i < MAX_SCENE)
	{
		if (!ft_strncmp(cols[0], data[i].type, ft_strlen(data[i].type) + 1))
		{
			node->content = ft_calloc(1, data[i].size);
			if (node->content && !(data[i].parse(node->content, cols + 1)))
			{
				ft_lstadd_back(&scene[i], node);
				return (EXIT_SUCCESS);
			}
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_FAILURE);
}

int	append2scene(t_list **scene, char **cols)
{
	t_list	*node;

	if (!ft_strncmp(cols[0], "\n", 2) || !ft_strncmp(cols[0], "\r\n", 3))
		return (EXIT_SUCCESS);
	node = ft_lstnew(NULL);
	if (node == NULL)
		return (ft_error(__func__, __FILE__, __LINE__));
	if (_append(scene, node, cols) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	ft_lstdelone(node, free);
	if (errno == 0)
		errno = EINVAL;
	return (ft_error(__func__, __FILE__, __LINE__));
}
