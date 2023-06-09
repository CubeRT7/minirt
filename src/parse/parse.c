/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:42:29 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/07 07:10:22 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	_invalid(int argc, char **argv)
{
	char	*extension;

	if (argc != 2 || argv == NULL || argv[1] == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	extension = ft_strrchr(argv[1], '.');
	if (extension == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (ft_strncmp(extension, ".rt", 4) != 0)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	return (EXIT_SUCCESS);
}

static int	_parse_elements(t_list	**elements, int fd)
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
		ret = append_element(elements, cols);
		{
			ft_strarr_free(cols);
			if (ret == EXIT_FAILURE)
				return (ft_error(__func__, __FILE__, __LINE__, 0));
		}
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

static int	_convert_to_objs(t_list **elems, t_list **objs)
{
	static const t_new_object	new[MAX_ELEMENT_TYPE] = {
	[AmbientLight] = new_ambient_light,
	[Camera] = new_camera,
	[Light] = new_light,
	[Plane] = new_plane,
	[Sphere] = new_sphere,
	[Cylinder] = new_cylinder};
	int							i;
	t_list						*converted;

	i = 0;
	while (i < MAX_ELEMENT_TYPE)
	{
		converted = ft_lstmap(elems[i], new[i], destory_object);
		if (converted == NULL)
		{
			ft_lstclear(objs, destory_object);
			return (ft_error(__func__, __FILE__, __LINE__, 0));
		}
		ft_lstadd_front(objs, converted);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	_exit_parse(int exit_code)
{
	clear_elements();
	return (exit_code);
}

int	parse(t_list **result, int argc, char **argv)
{
	int		fd;
	int		ret;
	t_list	**elements;

	if (_invalid(argc, argv) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	elements = get_elements();
	ret = _parse_elements(elements, fd);
	close(fd);
	if (_convert_to_objs(elements, result))
		return (_exit_parse(ft_error(__func__, __FILE__, __LINE__, 0)));
	if (ret == EXIT_FAILURE)
		return (_exit_parse(ft_error(__func__, __FILE__, __LINE__, 0)));
	if (ft_lstsize(elements[AmbientLight]) > 1
		|| ft_lstsize(elements[Camera]) > 1
		|| ft_lstsize(elements[Light]) > 1)
		return (_exit_parse(ft_error(__func__, __FILE__, __LINE__, EINVAL)));
	return (_exit_parse(EXIT_SUCCESS));
}
