# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:39:07 by minjungk          #+#    #+#              #
#    Updated: 2023/05/30 22:22:56 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

MAKEFLAGS	= -j 8

LIBS = libft/libft.a

all bonus clean fclean re:
	@for dir in $(dir $(LIBS)); do \
		$(MAKE) -C $$dir $@; \
	done

.PHONY: all clean fclean re bonus
