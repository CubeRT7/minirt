# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:39:07 by minjungk          #+#    #+#              #
#    Updated: 2023/07/13 00:46:58 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

MAKEFLAGS	= -j 8

LIBS = \
	libft/libft.a \
	libcustom/libcustom.a \
	libvector/libvector.a \

all bonus clean fclean re:
	@for dir in $(dir $(LIBS)); do \
		$(MAKE) -C $$dir $@; \
	done

.PHONY: all clean fclean re bonus
