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

NAME 	= libmlp

LIB_DIR	= ../GCmalloc

INC_DIR	= ../../include

CC 	= gcc

SRC 	= src/main.c \

OBJ 	= $(SRC:.c=.o)

CFLAGS 	= -Wall -Werror -Wextra -ansi -pedantic -I$(INC_DIR)

$(NAME):$(LIB) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo -e "\e[1;32mLibrary multilayer perceptron OK\e[m"
	@mv $(NAME) ../

$(LIB):
	@(cd $(LIB_DIR) && $(MAKE) $@)

all: $(NAME)

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@rm -f $(OBJ)

fclean: clean
	@(cd $(LIB_DIR) && $(MAKE) $@)
	@rm -f ../$(NAME)

re: fclean all
