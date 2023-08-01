/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:42:29 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/01 19:33:56 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

extern int	deserialize(t_element **rtn, const char *line);

static int	_append(struct s_rt_file *rt, t_element *element)
{
	t_list	*node;

	if (element == NULL)
		return (EXIT_SUCCESS);
	node = ft_lstnew(element);
	if (node == NULL)
	{
		free(element);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	else if (element->type == AmbientLight)
		ft_lstadd_back(&rt->ambient_light, node);
	else if (element->type == Camera)
		ft_lstadd_back(&rt->camera, node);
	else if (element->type == Light)
		ft_lstadd_back(&rt->lights, node);
	else
		ft_lstadd_back(&rt->objs, node);
	return (EXIT_SUCCESS);
}

static int	_read(struct s_rt_file *rt, int fd)
{
	int			ret;
	char		*line;
	t_element	*element;

	line = get_next_line(fd);
	while (line)
	{
		ret = deserialize(&element, line);
		free(line);
		if (ret == EXIT_FAILURE || _append(rt, element) == EXIT_FAILURE)
		{
			clean_rt(rt);
			return (ft_error(__func__, __FILE__, __LINE__, 0));
		}
		line = get_next_line(fd);
	}
	if (ft_lstsize(rt->ambient_light) < 2
		&& ft_lstsize(rt->camera) < 2
		&& ft_lstsize(rt->lights) < 2)
		return (EXIT_SUCCESS);
	clean_rt(rt);
	return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
}

int	import_file(struct s_rt_file *rt, int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*extension;

	if (rt == NULL || argc != 2 || argv == NULL || argv[1] == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	extension = ft_strrchr(argv[1], '.');
	if (extension == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	if (ft_strncmp(extension, ".rt", 4) != 0)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	ret = _read(rt, fd);
	close(fd);
	if (ret == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	return (EXIT_SUCCESS);
}
