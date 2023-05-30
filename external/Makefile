# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:46:16 by minjungk          #+#    #+#              #
#    Updated: 2023/05/31 00:27:45 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

RM = rm -rf

# **************************************************************************** #
LIBMLX_DIR	=	MLX42
LIBMLX_OBJ	=	$(LIBMLX_DIR)/build
LIBMLX_LIB	=	$(LIBMLX_OBJ)/libmlx42.a

$(LIBMLX_OBJ):
	cmake $(LIBMLX_DIR) -B $(LIBMLX_OBJ)

$(LIBMLX_LIB): $(LIBMLX_OBJ)
	$(MAKE) -C $(LIBMLX_OBJ) -j4

libmlx_all: $(LIBMLX_LIB)

libmlx_fclean:
	$(RM) $(LIBMLX_OBJ)

libmlx_re:
	$(MAKE) libmlx_fclean
	$(MAKE) libmlx_all

# **************************************************************************** #

all bonus:
	$(MAKE) libmlx_all

clean fclean:
	$(MAKE) libmlx_fclean

re:
	$(MAKE) libmlx_re

.PHONY: all clean fclean re bonus

