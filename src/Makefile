# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:51:46 by minjungk          #+#    #+#              #
#    Updated: 2023/05/31 00:55:17 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -O2 -ffast-math
CPPFLAGS	= -I.
LDFLAGS		= -L.
LDLIBS		= -lm

CPPFLAGS	= -I../external/MLX42/include
LDFLAGS		= -L../external/MLX42/build
LDLIBS		= -lmlx42

CPPFLAGS	= -I../lib/libft
LDFLAGS		= -L../lib/libft
LDLIBS		= -lft

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
	CPPFLAGS	= -D__DEBUG__
	CFLAGS		= -g -O0 -ffast-math
endif

# **************************************************************************** #
MINIRT = miniRT

MINIRT_SRCS = \
	$(MINIRT).c
MINIRT_OBJS = $(MINIRT_SRCS:.c=.o)
MINIRT_DEPS = $(MINIRT_SRCS:.c=.d)
-include $(MINIRT_DEPS)

$(MINIRT): $(MINIRT_OBJS)

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