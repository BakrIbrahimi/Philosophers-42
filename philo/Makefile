NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC = philo.h

SRC = philo.c \
		check.c\
		init_philo.c\
		philo_utils.c\
		death.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME):$(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)

re: fclean all
