/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:42:29 by minjungk          #+#    #+#             */
/*   Updated: 2023/08/02 16:01:30 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <fcntl.h>

extern int	serialize(int fd, t_element *element);

static int	_write(t_world *world, int fd)
{
	t_list	*curr;

	if (world->ambient_light
		&& serialize(fd, (t_element *)world->ambient_light) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (world->camera
		&& serialize(fd, (t_element *)world->camera) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	curr = world->lights;
	while (curr)
	{
		if (serialize(fd, curr->content) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	curr = world->objs;
	while (curr)
	{
		if (serialize(fd, curr->content) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}

int	export_file(t_world *world)
{
	int		fd;
	int		ret;

	if (world->device.keyboard[KEYBOARD_F12] == 0)
		return (EXIT_SUCCESS);
	world->device.keyboard[KEYBOARD_F12] = 0;
	fd = open("save.rt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		perror(":");
		return (EXIT_FAILURE);
	}
	ret = _write(world, fd);
	close(fd);
	if (ret == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		perror(":");
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("Successfully saving object to save.rt\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
