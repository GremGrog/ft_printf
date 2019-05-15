# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmebble <qmebble@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 18:13:43 by qmebble           #+#    #+#              #
#    Updated: 2018/12/04 19:58:02 by qmebble          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = *.c
OBJ = *.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
$(OBJ) : $(SRC)
	@gcc $(FLAGS) -c $(SRC)

clean:
	@rm -rf $(OBJ)

fclean:
	@rm -rf $(NAME) $(OBJ)

re: fclean all
