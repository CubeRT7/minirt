/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:42:29 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/09 23:56:55 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

static int	_append(t_list **elements, t_list *node, char **cols)
{
	int									i;
	static const struct s_parse_info	data[MAX_ELEMENT_TYPE] = {
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

static int	_append_element(t_list **elements, char **cols)
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

static int	_append_elements(t_list **elements, int fd)
{
	int		ret;
	char	*line;
	char	**cols;

	line = get_next_line(fd);
	while (line)
	{
		cols = ft_split(line, ' ');
		{
			free(line);
			if (cols == NULL)
				return (ft_error(__func__, __FILE__, __LINE__, 0));
		}
		ret = _append_element(elements, cols);
		{
			ft_strarr_free(cols);
			if (ret == EXIT_FAILURE)
				return (ft_error(__func__, __FILE__, __LINE__, 0));
		}
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

static int	_read(t_list **objs, int fd)
{
	int		i;
	int		ret;
	t_list	*elements[MAX_ELEMENT_TYPE];

	ft_memset(elements, 0, sizeof(elements));
	ret = _append_elements(elements, fd);
	if (ret == EXIT_SUCCESS)
	{
		if (ft_lstsize(elements[AmbientLight]) < 2
			&& ft_lstsize(elements[Camera]) < 2
			&& ft_lstsize(elements[Light]) < 2)
		{
			i = 0;
			while (i < MAX_ELEMENT_TYPE)
				ft_lstadd_back(objs, elements[i++]);
			return (EXIT_SUCCESS);
		}
	}
	i = 0;
	while (i < MAX_ELEMENT_TYPE)
		ft_lstclear(&elements[i++], free);
	return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
}

int	import_file(t_list **objs, int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*extension;

	if (objs == NULL || argc != 2 || argv == NULL || argv[1] == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	extension = ft_strrchr(argv[1], '.');
	if (extension == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (ft_strncmp(extension, ".rt", 4) != 0)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ret = _read(objs, fd);
	close(fd);
	if (ret == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	return (EXIT_SUCCESS);
}
