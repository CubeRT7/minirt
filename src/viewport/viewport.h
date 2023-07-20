/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 07:21:10 by minjungk          #+#    #+#             */
/*   Updated: 2023/07/20 08:50:26 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWPORT_H
# define VIEWPORT_H
# include "mlx.h"
# include "hook.h"
# include "libcustom.h"

# define TITLE "CubeRT7"
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define WINDOW_WIDTH_SEPARATE 128
# define WINDOW_HEIGHT_SEPARATE 128

typedef struct s_mouse
{
	t_vector3	prev;
	t_vector3	curr;
	int			action[MAX_MOUSE_KEY];
}	t_mouse;

typedef struct s_viewport
{
	void		*mlx;
	void		*win;
	void		*img;
	t_vector3	size;
	t_vector3	separated_render_max;
	t_vector3	separated_render_curr;
	t_mouse		mouse;
	int			keyboard[MAX_KEYBOARD];
}	t_viewport;

extern void	destroy_viewport(struct s_viewport *viewport);
extern int	create_viewport(struct s_viewport *viewport);

#endif
