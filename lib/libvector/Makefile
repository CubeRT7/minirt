# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 16:16:38 by yonshin           #+#    #+#              #
#    Updated: 2023/06/09 18:31:28 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

NAME = libvector.a

CFLAGS		= -Wall -Wextra -Werror -MMD -MP

ifdef	DEBUG
	CPPFLAGS	+= -D__DEBUG__
	CFLAGS		= -g -O0
endif

SRCS = \
	vector3.c \
	v3_add.c \
	v3_sub.c \
	v3_mul.c \
	v3_dot.c \
	v3_cross.c \
	v3_hadamard.c \
	v3_magnitude.c \
	v3_normalize.c \
	v3_reverse.c \
	v3_rotate.c \
	v3_rotate_axis.c \
	v3_preset.c \

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
