# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/23 06:01:31 by minjungk          #+#    #+#              #
#    Updated: 2023/07/23 06:03:30 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DELETE_ON_ERROR:
.DEFAULT_GOAL := all

MINIRT = miniRT

export MFLAGS := $(MAKEFLAGS)

all $(MINIRT):
	$(MAKE) -f Makefile.mandatory

bonus:
	$(MAKE) -f Makefile.bonus

clean:
	find . -type f \( -name '*.o' -or -name '*.d' \) -print -delete

fclean: clean
	$(RM) $(MINIRT)

re: fclean
	$(MAKE) $(MINIRT)

exe: $(MINIRT)
	-export DYLD_LIBRARY_PATH=./external/minilibx; \
	./$(MINIRT) $(ARGS)

.PHONY: all clean fclean re bonus $(MINIRT)
