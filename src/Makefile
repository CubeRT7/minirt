# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:51:46 by minjungk          #+#    #+#              #
#    Updated: 2023/06/09 22:55:36 by minjungk         ###   ########.fr        #
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

CPPFLAGS	+= -Iparse
CPPFLAGS	+= -Isimulate

MINIRT_SRCS = \
	Element/common.c \
	Element/object.c \
	Element/AmbientLight/ambient_light.c \
	Element/Camera/camera.c \
	Element/Light/light.c \
	Element/Plane/plane.c \
	Element/Sphere/sphere.c \
	Element/Cylinder/cylinder.c \
	parse/parse.c \
	simulate/simulate.c \
	simulate/hook_key_event.c \
	simulate/hook_draw.c \
	simulate/hook_resize_event.c \
	simulate/hook_close_event.c \
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
