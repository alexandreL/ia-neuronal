# **************************************************************************** #
#                                                                              #
#                                                       /\ ___ /\              #
#    Makefile                                          (  o   o  )             #
#                                                       \  >#<  /              #
#    By: alex <alexandre.loubeyres@gmail.com>           /       \              #
#                                                      /         \       ^     #
#    Created: 2015/08/03 11:38:50 by alex             |           |     //     #
#    Updated: 2015/08/03 11:49:33 by alex              \         /    //       #
#                                                       ///  ///   --          #
#                                                                              #
# **************************************************************************** #

LIB_DIR	= lib/MLP

LIBMLP:
	@(cd $(LIB_DIR) && $(MAKE))

all: LIBMLP

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)

fclean: clean
	@(cd $(LIB_DIR) && $(MAKE) $@)

re: fclean all
