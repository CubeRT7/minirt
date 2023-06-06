/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgui.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 05:26:49 by yonshin           #+#    #+#             */
/*   Updated: 2023/06/05 06:51:53 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGUI_H
# define LIBGUI_H

# include "MLX42/MLX42.h"
# include "libcustom.h"

# define DEFAULT_FOCAL_WIDTH 2.0f
# define DEFAULT_MAX_DEPTH 50
# define DEFAULT_IGNORE_DELTA 0.001f
# define DEFAULT_SAMPLE_PER_PIXEL 10

typedef struct s_gui_setting
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		*title;
	float		focal_length;
	float		max_depth;
	float		ignore_delta;
	float		sample_per_pixel;
}	t_gui_setting;

int		gui_setting(t_gui_setting *g, int width, int height, char *title);
void	gui_open_window(t_gui_setting *g);

#endif
