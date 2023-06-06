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

int	parse(t_list **elements, int argc, char **argv)
{
	int	fd;
	int	ret;

	if (_invalid(argc, argv) == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	elements = get_elements();
	ret = _parse_elements(elements, fd);
	close(fd);
	if (ret == EXIT_FAILURE)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (ft_lstsize(elements[AmbientLight]) > 1
		|| ft_lstsize(elements[Camera]) > 1
		|| ft_lstsize(elements[Light]) > 1)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	return (EXIT_SUCCESS);
}
