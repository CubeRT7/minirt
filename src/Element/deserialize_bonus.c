/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deserialize_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:56:58 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/01 19:34:56 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "element.h"

extern t_element	*deserialize_ambient_light(const char *line);
extern t_element	*deserialize_camera(const char *line);
extern t_element	*deserialize_light(const char *line);
extern t_element	*deserialize_sphere(const char *line);
extern t_element	*deserialize_plane(const char *line);
extern t_element	*deserialize_cylinder(const char *line);
extern t_element	*deserialize_cone(const char *line);

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
	else if (ft_strncmp(line, "co ", 3) == 0)
		*rtn = deserialize_cone(line + 3);
	if (*rtn == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, EINVAL));
	return (EXIT_SUCCESS);
}

int	serialize(int fd, t_element *element)
{
	if (element == NULL)
		return (EXIT_SUCCESS);
	else if (element->type == AmbientLight)
		write(fd, "A ", 2);
	else if (element->type == Camera)
		write(fd, "C ", 2);
	else if (element->type == Light)
		write(fd, "L ", 2);
	else if (element->type == Plane)
		write(fd, "pl ", 3);
	else if (element->type == Sphere)
		write(fd, "sp ", 3);
	else if (element->type == Cylinder)
		write(fd, "cy ", 3);
	element->func[Serialize](element, fd);
	if (errno)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	return (EXIT_SUCCESS);
}
