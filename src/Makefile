# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:51:46 by minjungk          #+#    #+#              #
#    Updated: 2023/05/30 22:16:02 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP -O2 -ffast-math
CPPFLAGS	= -I.
LDFLAGS		= -L.
LDLIBS		= -lm

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
