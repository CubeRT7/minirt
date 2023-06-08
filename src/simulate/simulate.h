
#ifndef SIMULATE_H
# define SIMULATE_H

# include "MLX42/MLX42.h"
# include "hook.h"
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

typedef struct s_world
{
	t_list			*objs;
	t_gui_setting	gui;
}	t_world;

int simulate(t_list *objs, int width, int height, char *title);

#endif
