# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:20:46 by minjungk          #+#    #+#              #
#    Updated: 2023/06/08 15:16:27 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
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

.PHONY: all clean fclean re bonus $(MINIRT)
