CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = philo
OBJ = parsing.o main.o utils.o forks.o routines.o

all : $(NAME)

$(NAME) : $(OBJ) philosopher.h
	@$(CC)  $(OBJ) -o $(NAME)
%.o : %.c
	@$(CC)  -c $< -o $@
clean :
	@rm -rf $(OBJ)
fclean : clean
	@rm -rf $(NAME)