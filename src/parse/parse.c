/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:42:29 by minjungk          #+#    #+#             */
/*   Updated: 2023/06/05 05:46:22 by minjungk         ###   ########.fr       */
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
		ret = append2scene(scene, cols);
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
