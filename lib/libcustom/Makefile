# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 02:34:32 by minjungk          #+#    #+#              #
#    Updated: 2023/07/13 00:33:35 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

NAME = libcustom.a

CFLAGS		= -Wall -Wextra -Werror -MMD -MP
CPPFLAGS	= -I../libft
ARFLAGS		= rsc

ifdef	DEBUG
	CPPFLAGS	+= -D__DEBUG__
	CFLAGS		= -g -O0
endif

SRCS = \
	ft_error.c \
	ft_strtof.c \
	ft_strarr_free.c \
	ft_ftoa.c \

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
