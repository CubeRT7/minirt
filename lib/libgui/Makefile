# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 05:16:23 by yonshin           #+#    #+#              #
#    Updated: 2023/06/05 06:44:51 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

NAME = libgui.a

CFLAGS		= -Wall -Wextra -Werror -MMD -MP

CPPFLAGS	+= -I../../external/MLX42/include
LDFLAGS		+= -L../../external/MLX42/build
LDLIBS		+= -lmlx42

CPPFLAGS	+= -I../libcustom
LDFLAGS		+= -L../libcustom
LDLIBS		+= -lcustom

CPPFLAGS	+= -I../libft
LDFLAGS		+= -L../libft
LDLIBS		+= -lft

ifdef	DEBUG
	CPPFLAGS	+= -D__DEBUG__
	CFLAGS		= -g -O0
endif

SRCS = \
	gui_setting.c \
	gui_open_window.c \

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)
-include $(DEPS)

all bonus: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(wildcard *.o) $(wildcard *.d)

fclean: clean
	$(RM) $(NAME)

re: fclean
	$(MAKE) $(NAME)

.PHONY: all clean fclean re bonus
