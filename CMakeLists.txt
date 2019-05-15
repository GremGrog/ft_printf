cmake_minimum_required(VERSION 3.13)

set (PROJECT ft_printf)

project (${PROJECT})

set (HEADERS
        MainHeader/ft_printf.h

		)

set (SOURCES
		Srcs/HighestFunctions/char_bin_search.c
		Srcs/HighestFunctions/ft_printf.c
		Srcs/HighestFunctions/ft_set_to_null.c
		Srcs/HighestFunctions/Parsing
		Srcs/HighestFunctions/Parsing/ft_parsing.c
		Srcs/HighestFunctions/Parsing/string_before.c
		Srcs/HighestFunctions/Parsing/ft_str_after.c
		Srcs/HighestFunctions/Parsing/put_data.c
		Srcs/HighestFunctions/Parsing/set_flags.c
		Srcs/HighestFunctions/Parsing/set_indents.c
		Srcs/HighestFunctions/Parsing/set_modificators.c
		Srcs/HighestFunctions/Parsing/set_precision.c
		Srcs/HighestFunctions/ft_strrev.c
		Srcs/HighestFunctions/assembler.c
		Srcs/HighestFunctions/num_len.c
		Srcs/HighestFunctions/ft_put_str.c
		Srcs/Char/char.c
		Srcs/String/string.c
		Srcs/DI/ft_di.c
		Srcs/DI/check_limits_integer.c
		Srcs/DI/ft_itoa_integer.c
		Srcs/DI/ft_put_indents_integer.c
		Srcs/DI/ft_put_precision_integer.c
		Srcs/DI/ft_put_sign_integer.c
		Srcs/DI/ft_put_space_integer.c
		Srcs/DI/ft_itoa_int_binary.c
		Srcs/HighestFunctions/dynamic_buffer.c
		Srcs/Pointer/ft_put_grid_pointer.c
		Srcs/Pointer/ft_put_indents_pointer.c
		Srcs/Pointer/pointer.c
		Srcs/Pointer/ft_itoa_pointer.c
		Srcs/Pointer/ft_put_precision_pointer.c
		Srcs/OxX/ox.c
		Srcs/OxX/grid_o.c
		Srcs/OxX/grid_x.c
		Srcs/OxX/ft_caps.c
		Srcs/OxX/indents_ox.c
		Srcs/OxX/fill_precision.c
		Srcs/OxX/itoa_base.c
		Srcs/OxX/itoa_u.c
		Srcs/Unsigned/check_limits_unsigned_integer.c
		Srcs/Unsigned/ft_itoa_unsigned.c
		Srcs/Unsigned/ft_put_indents_unsigned.c
		Srcs/Unsigned/ft_put_precision_unsigned.c
		Srcs/Unsigned/ft_unsigned.c
		Srcs/Unsigned/num_len_unsigned.c
		Srcs/Unsigned/ft_itoa_u_bin.c
		Srcs/Float/floats.c
		Srcs/Float/floats_manipulation.c
		Srcs/Float/set_precision_flo.c
		Srcs/Float/num_to_arr.c
		libft/ft_abs.c
		libft/ft_atoi.c
		libft/ft_bzero.c
		libft/ft_isalnum.c
		libft/ft_isalpha.c
		libft/ft_isascii.c
		libft/ft_isdigit.c
		libft/ft_isprint.c
		libft/ft_itoa.c
		libft/ft_lstadd.c
		libft/ft_lstdel.c
		libft/ft_lstdelone.c
		libft/ft_lstiter.c
		libft/ft_lstmap.c
		libft/ft_lstnew.c
		libft/ft_mascut.c
		libft/ft_memalloc.c
		libft/ft_memccpy.c
		libft/ft_memchr.c
		libft/ft_memcmp.c
		libft/ft_memcpy.c
		libft/ft_memdel.c
		libft/ft_memmove.c
		libft/ft_memset.c
		libft/ft_pow.c
		libft/ft_putchar.c
		libft/ft_putchar_fd.c
		libft/ft_putendl.c
		libft/ft_putendl_fd.c
		libft/ft_putnbr.c
		libft/ft_putnbr_fd.c
		libft/ft_putstr.c
		libft/ft_putstr_fd.c
		libft/ft_realloc.c
		libft/ft_strcat.c
		libft/ft_strchr.c
		libft/ft_strclr.c
		libft/ft_strcmp.c
		libft/ft_strcpy.c
		libft/ft_strdel.c
		libft/ft_strdup.c
		libft/ft_strequ.c
		libft/ft_strfix.c
		libft/ft_striter.c
		libft/ft_striteri.c
		libft/ft_strjoin.c
		libft/ft_strlcat.c
		libft/ft_strlen.c
		libft/ft_strmap.c
		libft/ft_strmapi.c
		libft/ft_strncat.c
		libft/ft_strncmp.c
		libft/ft_strncpy.c
		libft/ft_strnequ.c
		libft/ft_strnew.c
		libft/ft_strnstr.c
		libft/ft_strrchr.c
		libft/ft_strsplit.c
		libft/ft_strstr.c
		libft/ft_strsub.c
		libft/ft_strtrim.c
		libft/ft_tolower.c
		libft/ft_toupper.c
		Srcs/Float/indents_flo.c
		Srcs/OxX/itoa_u.c
		Srcs/Float/set_precision_flo.c
		Srcs/Float/floats_manipulation.c
		Srcs/Float/ohter_case.c
		Srcs/Float/set_space_flo.c
		Srcs/Float/set_plus_flo.c
		Srcs/Float/ipart_to_str.c Srcs/Float/long_d.c)

add_executable(${PROJECT} ${SOURCES} ${HEADERS})