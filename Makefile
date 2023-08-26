# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:20:46 by minjungk          #+#    #+#              #
#    Updated: 2023/07/15 11:46:44 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

MINIRT = miniRT

export MFLAGS := $(MAKEFLAGS)

all bonus $(MINIRT):
	$(MAKE) -C external
	$(MAKE) -C lib
	$(MAKE) -C src $@
	ln -sf ./src/$(MINIRT) $(MINIRT)

clean:
	$(MAKE) -C external $@
	$(MAKE) -C lib $@
	$(MAKE) -C src $@

fclean:
	$(MAKE) -C external $@
	$(MAKE) -C lib $@
	$(MAKE) -C src $@
	$(RM) $(MINIRT)

re: fclean
	$(MAKE) $(MINIRT)

test:
	make DEBUG=1 all
	./$(MINIRT) data/minimalist.rt

exe: $(MINIRT)
	-export DYLD_LIBRARY_PATH=./external/minilibx; \
	./$(MINIRT) $(ARGS)

.PHONY: all clean fclean re bonus $(MINIRT)
