CC = cc
FLAGS = -Wall -Werror -Wextra
NAME = philo
OBJ = parsing.o main.o utils.o death.o forks.o routines.o

all : $(NAME)

$(NAME) : $(OBJ) philosopher.h
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@
clean :
	@rm -rf $(OBJ)
fclean : clean
	@rm -rf $(NAME)