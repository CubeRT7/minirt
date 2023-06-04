# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:20:46 by minjungk          #+#    #+#              #
#    Updated: 2023/06/04 22:21:10 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

MINIRT = miniRT

all bonus $(MINIRT):
	$(MAKE) $(MAKEFLAGS) -C external
	$(MAKE) $(MAKEFLAGS) -C lib
	$(MAKE) $(MAKEFLAGS) -C src $@
	ln -sf ./src/$(MINIRT) $(MINIRT)

clean:
	$(MAKE) $(MAKEFLAGS) -C external $@
	$(MAKE) $(MAKEFLAGS) -C lib $@
	$(MAKE) $(MAKEFLAGS) -C src $@

fclean:
	$(MAKE) $(MAKEFLAGS) -C external $@
	$(MAKE) $(MAKEFLAGS) -C lib $@
	$(MAKE) $(MAKEFLAGS) -C src $@
	$(RM) $(MINIRT)

re: fclean
	$(MAKE) $(MAKEFLAGS) $(MINIRT)

.PHONY: all clean fclean re bonus $(MINIRT)
