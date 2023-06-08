
#include "simulate.h"

static void	_init_gui_setting(t_gui_setting *g, char *title)
{
	g->mlx = NULL;
	g->image = NULL;
	g->title = title;
	g->focal_length = DEFAULT_FOCAL_WIDTH;
	g->max_depth = DEFAULT_MAX_DEPTH;
	g->ignore_delta = DEFAULT_IGNORE_DELTA;
	g->sample_per_pixel = DEFAULT_SAMPLE_PER_PIXEL;
}

static int	_gui_setting(t_gui_setting *g, int width, int height, char *title)
{
	_init_gui_setting(g, title);
	g->mlx = mlx_init(width, height, g->title, true);
	if (g->mlx == NULL)
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	g->image = mlx_new_image(g->mlx, width, height);
	if (g->image == NULL)
	{
		mlx_close_window(g->mlx);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	if (mlx_image_to_window(g->mlx, g->image, 0, 0) == -1)
	{
		mlx_close_window(g->mlx);
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	}
	return (EXIT_SUCCESS);
}

static int _hook_setting(t_world *world)
{
	if (!mlx_loop_hook(world->gui.mlx, hook_key_event, &(world->gui)))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	if (!mlx_loop_hook(world->gui.mlx, hook_draw, world))
		return (ft_error(__func__, __FILE__, __LINE__, 0));
	mlx_resize_hook(world->gui.mlx, hook_resize_event, &(world->gui));
	mlx_close_hook(world->gui.mlx, hook_close_event, &(world->gui));
	return (EXIT_SUCCESS);
}

int simulate(t_list *objs, int width, int height, char *title)
{
	t_world	world;

	world.objs = objs;
    if (_gui_setting(&(world.gui), width, height, title))
        return (ft_error(__func__, __FILE__, __LINE__, 0));
    if (_hook_setting(&world))
        return (ft_error(__func__, __FILE__, __LINE__, 0));
    mlx_loop(world.gui.mlx);
	mlx_terminate(world.gui.mlx);
    return (EXIT_SUCCESS);
}
