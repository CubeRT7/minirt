# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 16:16:38 by yonshin           #+#    #+#              #
#    Updated: 2023/06/09 16:16:53 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

NAME = libvector.a

ifdef	DEBUG
	CPPFLAGS	+= -D__DEBUG__
	CFLAGS		= -g -O0
endif

SRCS = \
	vector3.c \
	v3_add.c \
	v3_cross_prod.c \
	v3_dot_prod.c \
	v3_magnitude.c \
	v3_mul.c \
	v3_normalize.c \
	v3_reverse.c \
	v3_sub.c \

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
