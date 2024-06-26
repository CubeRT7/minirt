/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_device.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:15:45 by yonshin           #+#    #+#             */
/*   Updated: 2023/07/28 13:20:28 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "device.h"

extern void	init_hook(struct s_device *dev);

static void	_init_screen_size(struct s_device *device)
{
	int			x;
	int			y;

	mlx_get_screen_size(device->mlx, &x, &y);
	x /= 3;
	y /= 3;
	if (WINDOW_WIDTH > 0)
		x = WINDOW_WIDTH;
	if (WINDOW_HEIGHT > 0)
		y = WINDOW_HEIGHT;
	device->size = vector3(x, y, 0);
	device->separated_render_max = vector3(
			(int)(1 + (int)device->size.x / WINDOW_WIDTH_SEPARATE),
			(int)(1 + (int)device->size.y / WINDOW_HEIGHT_SEPARATE),
			0);
}

int	create_device(struct s_device *dev)
{
	if (dev == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	dev->mlx = mlx_init();
	if (dev->mlx == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	_init_screen_size(dev);
	dev->win = mlx_new_window(dev->mlx, dev->size.x, dev->size.y, TITLE);
	if (dev->win == NULL)
	{
		destroy_device(dev);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	dev->img = mlx_new_image(dev->mlx, dev->size.x, dev->size.y);
	if (dev->img == NULL)
	{
		destroy_device(dev);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	init_hook(dev);
	return (EXIT_SUCCESS);
}
