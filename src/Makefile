# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:51:46 by minjungk          #+#    #+#              #
#    Updated: 2023/07/12 08:34:24 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -O2 -ffast-math
CPPFLAGS	= -I.
LDFLAGS		= -L.
LDLIBS		= -lm

CPPFLAGS	+= -I../external/MLX42/include
LDFLAGS		+= -L../external/MLX42/build
LDLIBS		+= -lmlx42

CPPFLAGS	+= -I../lib/libcustom
LDFLAGS		+= -L../lib/libcustom
LDLIBS		+= -lcustom

CPPFLAGS	+= -I../lib/libvector
LDFLAGS		+= -L../lib/libvector
LDLIBS		+= -lvector

CPPFLAGS	+= -I../lib/libft
LDFLAGS		+= -L../lib/libft
LDLIBS		+= -lft

ifneq ($(shell uname), Darwin)
	CPPFLAGS	+= -D__LINUX__
	LDFLAGS		+= -pthread
	LDLIBS		+= -ldl -lglfw
else
	LDLIBS		+= -lglfw
	LDFLAGS 	+= -L$(HOME)/.brew/lib
	LDFLAGS 	+= -framework Cocoa -framework OpenGL -framework IOKit
endif

ifdef	DEBUG
	CPPFLAGS	+= -D__DEBUG__
	CFLAGS		= -g -O0 -ffast-math
endif

# **************************************************************************** #
MINIRT = miniRT

CPPFLAGS	+= -Ifile
CPPFLAGS	+= -Isimulate

MINIRT_SRCS = \
	Element/common.c \
	Element/AmbientLight/init_ambient_light.c \
	Element/Camera/init_camera.c \
	Element/Camera/update_camera.c \
	Element/Light/init_light.c \
	Element/Plane/hit_plane.c \
	Element/Plane/init_plane.c \
	Element/Sphere/hit_sphere.c \
	Element/Sphere/init_sphere.c \
	Element/Cylinder/hit_cylinder.c \
	Element/Cylinder/init_cylinder.c \
	Element/util/range_in.c \
	Element/util/range_not_in.c \
	Element/util/get_ray_point.c \
	Element/util/get_face_normal.c \
	Element/util/close_to_zero.c \
	Element/util/quadratic_formula_root.c \
	file/clean_rt.c \
	file/import_file.c \
	file/parse_ambient_light.c \
	file/parse_camera.c \
	file/parse_light.c \
	file/parse_plane.c \
	file/parse_sphere.c \
	file/parse_cylinder.c \
	simulate/simulate.c \
	simulate/hook_key_event.c \
	simulate/hook_mouse_event.c \
	simulate/hook_draw.c \
	simulate/hook_draw_setting.c \
	simulate/hook_resize_event.c \
	simulate/hook_close_event.c \
	simulate/draw/hit.c \
	simulate/draw/ray_color.c \
	simulate/draw/color_to_pixel.c \
	simulate/draw/get_camera_ray.c \
	simulate/util/world_iter.c \
	$(MINIRT).c
MINIRT_OBJS = $(MINIRT_SRCS:.c=.o)
MINIRT_DEPS = $(MINIRT_SRCS:.c=.d)
-include $(MINIRT_DEPS)

$(MINIRT): $(MINIRT_OBJS) \
	../lib/libft/libft.a \
	../lib/libcustom/libcustom.a \
	../lib/libvector/libvector.a \

# **************************************************************************** #

all: $(MINIRT)

bonus: $(MINIRT)

clean:
	$(RM) $(MINIRT_OBJS) $(MINIRT_DEPS)

fclean: clean
	$(RM) $(MINIRT)

re: fclean
	$(MAKE) $(MINIRT)

.PHONY: all clean fclean re bonus 
