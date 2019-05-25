NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCF = Srcs/HighestFunctions/*.c \
		Srcs/HighestFunctions/Parsing/*.c \
		Srcs/Char/*.c \
		Srcs/String/*.c \
		Srcs/Pointer/*.c \
		Srcs/OxX/*.c \
		Srcs/DI/*.c \
		Srcs/Unsigned/*.c \
		Srcs/Float/*.c \
		libft/ft_*.c

OBJF = $(SRCF: %.c=%.o ($wildcard *.c))

INCLUDE = -I MainHeader/ft_printf.h -I libft/libft.h

all: $(NAME)

$(NAME): $(OBJF)
	gcc $(FLAGS) -c $(SRCF) $(INCLUDE)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f libft/*.o
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f libft/libft.a

re: fclean all