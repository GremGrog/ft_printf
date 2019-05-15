#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"
# define TYPES "%UXcdfiopsux"
# define D_TYPES "Xdioux"
# define NUMBERS "0123456789"
# define FLAGS " #+-0b"
# define CHECK_BIT(var, position) (var & (1 << position)) ? 1 : 0
# define PUT_BIT(var, position) (var |= (1 << position))
# define DEL_BIT(var, position) (var &= ~(1 << position))
# define MAX_CHAR				127
# define MAX_UNSIGNED_CHAR		255
# define MAX_SHORT_INT			32767
# define MAX_UNSIGNED_SHORT_INT	65535
# define MAX_INT				2147483647
# define MAX_LONG_INT			4294967296
# define MAX_LL_INT				9223372036854775807
# define MAX_ULL_INT			(unsigned long long)18446744073709551615

typedef struct			s_pf
{
	char				flags;
	char				modificators;
	int					indents;
	char				indents_symb;
	int					width;
	int					precision;
	char				type;
	short				base;
	long				return_value;
	char				*str_before;
	char				*str_middle;
	char				*str_after;
}						t_pf;

typedef struct			s_buffer
{
	char				*str;
	char				*final;
	size_t				str_len;
	size_t				before_len;
	size_t				after_len;
	unsigned int		buff_size;
	unsigned int		overflow_counter;
}						t_buffer;

t_buffer				*g_buffer;

/*
**						Char
*/

void					char_process(t_pf *data, va_list args);

/*
**						Integer
*/

long long int			g_integer;
void					ft_di(t_pf *data, va_list args);
long long int			check_limits_integer(t_pf *data, va_list args);
void					ft_put_sign_integer(t_pf *data);
void					ft_put_precision_integer(t_pf *data);
void					ft_itoa_integer(long long int num);
void					ft_itoa_int_binary(t_pf *data, long long int num);
void					ft_put_space_integer(t_pf *data);
void					ft_put_indents_integer(t_pf *data);

/*
**						Floats
*/

long					g_ipart;
double					g_fpart;
t_pf					*ft_floats(t_pf *data, va_list args);
void					set_indents_flo(t_pf *data);
void					multiplication_on_short(char *src, int num, char *dst);
char					*get_five_power(short exp, char *pow, char *bow);
void					number_to_arr(unsigned long mant, char *arr);
void					multiplication_loop(int j, char *x, char *y, char *z);
void					multiplication_long(char *x, char *y, char *z);
void					div_l(char *z, int n, char *y);
void					set_arr_to_null(char *arr);
void					get_mes(double flo);
void					other_case(char *y, short exp, short sign);
void					set_precision_flo(t_pf *data);
void					set_space_flo(t_pf *data);
void					set_plus_flo(t_pf *data);
void					ipart_to_str(void);
void					long_double_work(t_pf *data, va_list args);
void					validity(double flo);
/*
**						HighestFunctions
*/

int						ft_printf(const char *format, ...);
void					ft_set_to_null(t_pf *data);
int						num_len(long long int num);
void					ft_strrev(void);
char					*ft_itoa_base(t_pf *data, long long int num);
t_pf					*assemble_string(t_pf *data);
void					make_new_buffer(void);
void					check_and_add(size_t size);
void					free_buffer(void);
void					ft_put_str(t_pf *data);

/*
**						Parsing
*/

int						ft_parsing(t_pf *data, va_list args,
							const char *format, int i);
int						string_before(t_pf *data, const char *format, int i);
int						char_bin_search(char *str, char symb);
void					ft_set_to_null(t_pf *list);
int						set_flags(t_pf *data, const char *format, int i);
int						set_indents(t_pf *data, const char *format, int i);
int						set_precision(t_pf *data, const char *format, int i);
int						set_modificators(t_pf *data, const char *format, int i);
int						ft_str_after(t_pf *data, const char *format, int i);
t_pf					*put_data(t_pf *data, va_list args);

/*
**						OxX
*/

void					ox_process(t_pf *data, va_list args);
void					grid_x(t_pf *data);
void					grid_o(t_pf *data);
void					ft_caps(t_pf *list);
void					fill_plus(t_pf *data);
void					fill_indents_ox(t_pf *data);
void					fill_precision_ox(t_pf *data);
void					ft_itoa_base_ox(t_pf *data, long long int num);
void					ft_itoa_base_ox_max(t_pf *data,
						unsigned long long int num);

/*
**						Pointer
*/

unsigned long long int	g_pointer;
void					ft_pointer(t_pf *data, va_list args);
void					ft_itoa_pointer(unsigned long long int num);
void					ft_put_precision_pointer(t_pf *data);
void					ft_put_grid_pointer(t_pf *data);
void					ft_put_indents_pointer(t_pf *data);

/*
**						String
*/

void					string_process(t_pf *data, va_list args);

/*
**						Unsigned
*/

unsigned long long int	g_unsigned_integer;
void					ft_unsigned(t_pf *data, va_list args);
unsigned long long int	check_limits_unsigned(t_pf *data, va_list args);
int						num_len_unsigned(unsigned long long int num);
void					ft_itoa_unsigned(unsigned long long int num);
void					ft_itoa_u_binary(t_pf *data,
							unsigned long long int num);
void					ft_put_precision_unsigned(t_pf *data);
void					ft_put_indents_unsigned(t_pf *data);

#endif
