#include "../../MainHeader/ft_printf.h"

void	make_new_buffer(void)
{
	g_buffer = (t_buffer *)malloc(sizeof(t_buffer));
	g_buffer->buff_size = 50;
	g_buffer->str = (char *)malloc(sizeof(char) * (g_buffer->buff_size + 1));
	g_buffer->final = (char *)malloc(sizeof(char) * (g_buffer->buff_size + 1));
	ft_bzero(g_buffer->str, g_buffer->buff_size + 1);
	ft_bzero(g_buffer->final, g_buffer->buff_size + 1);
	g_buffer->str_len = 0;
	g_buffer->before_len = 0;
	g_buffer->after_len = 0;
	g_buffer->overflow_counter = 1;
}

void	ft_copy_temp(char *temp_str, char *temp_final)
{
	int i;

	i = g_buffer->str_len;
	ft_memcpy(temp_str, g_buffer->str, i);
	ft_memcpy(temp_final, g_buffer->final, i);
	while (i < g_buffer->buff_size)
	{
		temp_str[i] = '\0';
		temp_final[i] = '\0';
		i++;
	}
}

void	check_and_add(size_t size)
{
	char	*temp_str;
	char	*temp_final;

	if (g_buffer->str_len + size <= g_buffer->buff_size)
		return ;
	while (g_buffer->str_len + size > g_buffer->buff_size)
	{
		g_buffer->overflow_counter++;
		g_buffer->buff_size *= g_buffer->overflow_counter;
	}
	temp_str = (char *)malloc(sizeof(char) * g_buffer->buff_size);
	temp_final = (char *)malloc(sizeof(char) * g_buffer->buff_size);
	if (!temp_final || !temp_str)
		return ;
	ft_copy_temp(temp_str, temp_final);
	free(g_buffer->str);
	free(g_buffer->final);
	g_buffer->str = (char *)malloc(sizeof(char) * g_buffer->buff_size);
	g_buffer->final = (char*)malloc(sizeof(char) * g_buffer->buff_size);
	if (!g_buffer->str || !g_buffer->final)
		return ;
	ft_bzero(g_buffer->str, g_buffer->buff_size);
	ft_bzero(g_buffer->final, g_buffer->buff_size);
	ft_strcpy(g_buffer->str, temp_str);
	ft_strcpy(g_buffer->final, temp_final);
}

void	free_buffer(void)
{
	if (g_buffer->str != NULL)
		free(g_buffer->str);
	if (g_buffer->final != NULL)
		free(g_buffer->final);
	free(g_buffer);
}
