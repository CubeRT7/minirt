# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 22:39:21 by yonshin           #+#    #+#              #
#    Updated: 2023/07/13 01:03:38 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

NAME = libstr.a

CFLAGS		= -Wall -Wextra -Werror -MMD -MP
CPPFLAGS	= -I../libft
ARFLAGS		= rsc

ifdef	DEBUG
	CPPFLAGS	+= -D__DEBUG__
	CFLAGS		= -g -O0
endif

SRCS = \
	strb_add_left.c \
	strb_add_right.c \
	strb_build.c \
	strb_clear.c \
	strb_create_substr.c \
	strb_delete_str.c \
	strb_delete_substr.c \
	strb_fail_clear.c \
	strb_finish.c \
	strb_init.c \
	strb_new_node.c \

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
