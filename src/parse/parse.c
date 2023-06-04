/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:42:29 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/04 23:45:22 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	_invalid(int argc, char **argv)
{
	char	*extension;

	errno = EINVAL;
	if (argc != 2 || argv == NULL || argv[1] == NULL)
		return (ft_error(__func__, __FILE__, __LINE__));
	extension = ft_strrchr(argv[1], '.');
	if (extension == NULL)
		return (ft_error(__func__, __FILE__, __LINE__));
	if (ft_strncmp(extension, ".rt", 4) != 0)
		return (ft_error(__func__, __FILE__, __LINE__));
	errno = 0;
	return (EXIT_SUCCESS);
}

static int	_element(t_list	**scene, char **cols)
{
	if (!ft_strncmp(cols[0], "\n", 2) || !ft_strncmp(cols[0], "\r\n", 3))
		return (EXIT_SUCCESS);
	else if (!ft_strncmp(cols[0], "A", 2))
		return (parse_ambient_light(&scene[AmbientLight], cols + 1));
	else if (!ft_strncmp(cols[0], "C", 2))
		return (parse_camera(&scene[Camera], cols + 1));
	else if (!ft_strncmp(cols[0], "L", 2))
		return (parse_light(&scene[Light], cols + 1));
	else if (!ft_strncmp(cols[0], "pl", 3))
		return (parse_plane(&scene[Plane], cols + 1));
	else if (!ft_strncmp(cols[0], "sp", 3))
		return (parse_sphere(&scene[Sphere], cols + 1));
	else if (!ft_strncmp(cols[0], "cy", 3))
		return (parse_cylinder(&scene[Cylinder], cols + 1));
	errno = EINVAL;
	return (ft_error(__func__, __FILE__, __LINE__));
}

static int	_parse_scene(t_list	**scene, int fd)
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
				return (ft_error(__func__, __FILE__, __LINE__));
		}
		ret = _element(scene, cols);
		{
			ft_strarr_free(cols);
			if (ret == EXIT_FAILURE)
				return (ft_error(__func__, __FILE__, __LINE__));
		}
		line = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}

int	parse(t_list **scene, int argc, char **argv)
{
	int		fd;

	if (_invalid(argc, argv) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(__func__, __FILE__, __LINE__));
	scene = get_scene();
	if (_parse_scene(scene, fd) == EXIT_FAILURE
		|| ft_lstsize(scene[AmbientLight]) > 1
		|| ft_lstsize(scene[Camera]) > 1
		|| ft_lstsize(scene[Light]) > 1)
	{
		close(fd);
		if (errno == 0)
			errno = EINVAL;
		return (ft_error(__func__, __FILE__, __LINE__));
	}
	close(fd);
	return (EXIT_SUCCESS);
}
