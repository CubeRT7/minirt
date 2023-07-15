# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:46:16 by minjungk          #+#    #+#              #
#    Updated: 2023/07/14 15:55:03 by minjungk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_ON_ERROR:
.DEFAULT_GOAL := all

# **************************************************************************** #
LIBMLX_DIR	=	minilibx
LIBMLX_LIB	=	$(LIBMLX_OBJ)/libmlx42.a

$(LIBMLX_DIR):
	@if [ $(shell uname) = "Darwin" ]; then \
		ln -sf $(LIBMLX_DIR)-macos $(LIBMLX_DIR); \
	else \
		ln -sf $(LIBMLX_DIR)-linux $(LIBMLX_DIR); \
	fi

libmlx_fix: $(LIBMLX_DIR)
	sed -i 's///g' $(LIBMLX_DIR)/configure
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-return-type" $(LIBMLX_DIR)/Makefile.mk
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-parentheses" $(LIBMLX_DIR)/Makefile.mk
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-pointer-sign" $(LIBMLX_DIR)/Makefile.mk
	sed -i'' -r -e "/^CFLAGS\t=/a\CFLAGS+= -Wno-implicit-function-declaration" $(LIBMLX_DIR)/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-return-type" $(LIBMLX_DIR)/test/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-parentheses" $(LIBMLX_DIR)/test/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-pointer-sign" $(LIBMLX_DIR)/test/Makefile.mk
	sed -i'' -r -e "/^CFLAGS=/a\CFLAGS+= -Wno-implicit-function-declaration" $(LIBMLX_DIR)/test/Makefile.mk

libmlx_all: $(LIBMLX_DIR)
	$(MAKE) -C $(LIBMLX_DIR)

libmlx_clean: $(LIBMLX_DIR)
	$(MAKE) -C $(LIBMLX_DIR) clean

libmlx_fclean: libmlx_clean
	$(RM) $(LIBMLX_DIR)

.PHONY: $(LIBMLX_DIR) libmlx_fix libmlx_all libmlx_clean libmlx_fclean

# **************************************************************************** #

all bonus:
	$(MAKE) libmlx_all

clean:
	$(MAKE) libmlx_clean

fclean: libmlx_clean
	$(MAKE) libmlx_fclean

re:
	$(MAKE) libmlx_re

.PHONY: all clean fclean re bonus

