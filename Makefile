NAME = philo
SRC_DIR = sources
OBJ_DIR = .objs
green = \033[0;32m
red = \033[1;31m
pink = \033[0;35m
RESET = \033[0m
blue = \033[34;1m

SRC = $(wildcard ./*.c)

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = gcc
HEAD = -I./includes
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -pthread
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)
		@echo "$(green)~~~~~~~                                        %20"
		@sleep 0.1
		@echo "$(green)~~~~~~~~~~~~~                                  %40"
		@sleep 0.1
		@echo "$(green)~~~~~~~~~~~~~~~~~~~~                           %50"
		@sleep 0.1
		@echo "$(green)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~               %70"
		@sleep 0.1
		@echo "$(green)~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     %90"
		@sleep 0.1
		@echo "$(green)~~~~~~~~~~~~ COMPILING COMPLETED ~~~~~~~~~~~~~ %99$(RESET)"


clean:
		@$(RM) $(OBJ_DIR)
		@echo "$(green)[OK]$(RESET)   $(blue)Removing objects$(RESET)"

fclean: clean
		@$(RM) $(NAME)
		@echo "$(green)[OK]$(RESET)   $(blue)Removing philo$(RESET)"

re: fclean all

.PONY: all clean fclean re
