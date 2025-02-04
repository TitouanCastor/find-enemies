NAME = libmy.a

SRC =	main.c

OBJ = $(SRC:.c=.o)

BIN = find-enemies

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o $(BIN) $(NAME)

all:	$(NAME)

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(OBJ)
	rm -f *~
	rm -f lib/*~
	rm -f coding-style-reports.log
	rm -f ''#*#''
	rm -f $(BIN)

re: 	fclean all
