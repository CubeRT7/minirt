# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:20:46 by minjungk          #+#    #+#              #
#    Updated: 2023/05/31 00:19:24 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

MINIRT = miniRT

all bonus $(MINIRT):
	$(MAKE) -C external
	$(MAKE) -C src $@
	ln -sf ./src/$(MINIRT) $(MINIRT)

clean:
	$(MAKE) -C external $@
	$(MAKE) -C src $@

fclean:
	$(MAKE) -C external $@
	$(MAKE) -C src $@
	$(RM) $(MINIRT)

re: fclean
	$(MAKE) $(MINIRT)

.PHONY: all clean fclean re bonus $(MINIRT)
