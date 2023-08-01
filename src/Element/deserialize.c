/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:56:58 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 01:56:36 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

extern t_element	*deserialize_ambient_light(const char *line);
extern t_element	*deserialize_camera(const char *line);
extern t_element	*deserialize_light(const char *line);
extern t_element	*deserialize_sphere(const char *line);
extern t_element	*deserialize_plane(const char *line);
extern t_element	*deserialize_cylinder(const char *line);

int	deserialize(t_element **rtn, const char *line)
{
	t_element	*element;

	*rtn = NULL;
	while (line[0] == ' ')
		++line;
	if (!ft_strncmp(line, "\n", 2) || !ft_strncmp(line, "\r\n", 3))
		return (EXIT_SUCCESS);
	else if (ft_strncmp(line, "A ", 2) == 0)
		*rtn = deserialize_ambient_light(line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0)
		*rtn = deserialize_camera(line + 2);
	else if (ft_strncmp(line, "L ", 2) == 0)
		*rtn = deserialize_light(line + 2);
	else if (ft_strncmp(line, "pl ", 3) == 0)
		*rtn = deserialize_plane(line + 3);
	else if (ft_strncmp(line, "sp ", 3) == 0)
		*rtn = deserialize_sphere(line + 3);
	else if (ft_strncmp(line, "cy ", 3) == 0)
		*rtn = deserialize_cylinder(line + 3);
	if (*rtn == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	return (EXIT_SUCCESS);
}

int	serialize(int fd, t_element *element)
{
	errno = 0;
	if (element == NULL)
		return (EXIT_SUCCESS);
	else if (element->type == AmbientLight)
		ft_putstr_fd("A ", fd);
	else if (element->type == Camera)
		ft_putstr_fd("C ", fd);
	else if (element->type == Light)
		ft_putstr_fd("L ", fd);
	else if (element->type == Plane)
		ft_putstr_fd("pl ", fd);
	else if (element->type == Sphere)
		ft_putstr_fd("sp ", fd);
	else if (element->type == Cylinder)
		ft_putstr_fd("cy ", fd);
	element->func[Serialize](fd, element);
	if (errno)
		return (EXIT_FAILURE);
	ft_putchar_fd('\n', fd);
	return (EXIT_SUCCESS);
}
