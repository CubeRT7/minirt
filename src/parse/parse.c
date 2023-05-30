/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:42:29 by minjungk          #+#    #+#             */
/*   Updated: 2023/05/31 08:18:20 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	_invalid(int argc, char **argv)
{
	char	*extension;

	errno = EINVAL;
	if (argc != 2 || argv == NULL || argv[1] == NULL)
		return (EXIT_FAILURE);
	extension = ft_strrchr(argv[1], '.');
	if (extension == NULL)
		return (EXIT_FAILURE);
	if (ft_strncmp(extension, ".rt", 4) != 0)
		return (EXIT_FAILURE);
	errno = 0;
	return (EXIT_SUCCESS);
}

static int	_element(struct s_scene *scene, char *row)
{
	int				i;
	int				ret;
	char **const	cols = ft_split(row, ' ');

	ret = EXIT_FAILURE;
	if (cols[0] == NULL || ft_strncmp(cols[0], "\n", 2) == 0)
		ret = EXIT_SUCCESS;
	else if (ft_strncmp(cols[0], "A", 2) == 0)
		ret = parse_ambient_light(&scene->ambient_light, cols + 1);
	else if (ft_strncmp(cols[0], "C", 2) == 0)
		ret = parse_camera(&scene->camera, cols + 1);
	else if (ft_strncmp(cols[0], "L", 2) == 0)
		ret = parse_light(&scene->light, cols + 1);
	else if (ft_strncmp(cols[0], "pl", 3) == 0)
		ret = parse_plane(&scene->plane, cols + 1);
	else if (ft_strncmp(cols[0], "sp", 3) == 0)
		ret = parse_sphere(&scene->sphere, cols + 1);
	else if (ft_strncmp(cols[0], "cy", 3) == 0)
		ret = parse_cylinder(&scene->cylinder, cols + 1);
	i = 0;
	while (cols[i])
		free(cols[i++]);
	free(cols);
	return (ret);
}

static int	_read(struct s_scene *scene, char *filename)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (EXIT_FAILURE);
	ret = EXIT_SUCCESS;
	line = get_next_line(fd);
	while (line && ret == EXIT_SUCCESS)
	{
		ret = _element(scene, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (ret == EXIT_SUCCESS
		&& ft_lstsize(scene->ambient_light) < 2
		&& ft_lstsize(scene->camera) < 2
		&& ft_lstsize(scene->light) < 2)
		return (EXIT_SUCCESS);
	errno = EINVAL;
	return (EXIT_FAILURE);
}

int	parse(struct s_scene *scene, int argc, char **argv)
{
	if (_invalid(argc, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ft_bzero(scene, sizeof(struct s_scene));
	if (_read(scene, argv[1]) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	ft_lstclear(&scene->ambient_light, clear_ambient_light);
	ft_lstclear(&scene->camera, clear_camera);
	ft_lstclear(&scene->light, clear_light);
	ft_lstclear(&scene->plane, clear_plane);
	ft_lstclear(&scene->sphere, clear_sphere);
	ft_lstclear(&scene->cylinder, clear_cylinder);
	return (EXIT_FAILURE);
}
