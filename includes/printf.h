/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:33:14 by trlevequ          #+#    #+#             */
/*   Updated: 2018/12/13 17:17:31 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <string.h>
# include <stdarg.h>

typedef struct			s_data
{
	int					minus;
	int					plus;
	int					space;
	int					zero;
	int					hashtag;
	int					width;
	int					precision;
	int					size;
	int					hh;
	int					h;
	int					ll;
	int					l;
	int					j;
	int					len_param;
	char				type;
}						t_data;

int						ft_printf(const char *format, ...);

void					ft_putchar(char c);
void					ft_putnchar(char c, size_t n);
void					ft_putnstr(const char *str, size_t n);
void					ft_putstr(const char *str);
size_t					ft_strlen(const char *str);
unsigned long long		ft_strclen(const char *str);

void					ft_convert_base(unsigned long long nb, char *str);
void					ft_long_convert_base(unsigned long long nb, char *str);
int						ft_count_base(unsigned long long nb, char *str);
int						ft_unsigned_count_base(unsigned long long nb,
						char *str);

char					*ft_itoa(long long int nb, char tab[]);
char					*ft_unsigned_itoa(unsigned long long int nb,
						char tab[]);
char					*ft_short_itoa(short int nb, char tab[]);
char					*ft_unsigned_short_itoa(unsigned short int nb,
						char tab[]);
char					*ft_char_itoa(char nb, char tab[]);
char					*ft_unsigned_char_itoa(unsigned char nb,
						char tab[]);
char					*ft_char_to_str(char c, char tab[]);

long long int			ft_atoi(const char *str);
unsigned long long int	ft_unsigned_atoi(const char *str);

void					ft_init_data(t_data *data);
void					ft_fill_flags(const char **format, t_data *data);
void					ft_fill_width(const char **format, t_data *data);
void					ft_fill_precision(const char **format, t_data *data);
void					ft_fill_size(const char **format, t_data *data);
void					ft_fill_type(const char **format, t_data *data);
void					ft_fill_data_len_param(t_data *data, char *param);
t_data					ft_fill_data(const char **format);

char					*ft_param_no_size(va_list ap, t_data data,
						char tab[]);
char					*ft_param_size_l(va_list ap, t_data data,
						char tab[]);
char					*ft_param_size_h(va_list ap, t_data data,
						char tab[]);
char					*ft_param_size_hh(va_list ap, t_data data,
						char tab[]);

void					ft_print_param_no_size(t_data data, char *param,
						int size_param);
void					ft_print_param_size_l(t_data data, char *param,
						int size_param);
void					ft_print_param(t_data data, char *param,
						int size_param);

int						get_if_plus(t_data data, char *param);
int						get_if_space(t_data data, char *param);
int						get_if_hashtag(t_data data, char *param);
void					put_if_hashtag(t_data data);

void					get_precision(t_data *data, char *param);
void					get_size_str(t_data *data, char *param, int *size_str);
void					get_nb_space(t_data *data, char *param,
						int *size_str, int *nb_space);

int						print_if_minus(t_data *data, char *param,
						int *nb_space);
int						print_before_param(t_data *data, char *param,
						int *nb_space);
int						ft_before_param(t_data *data, char *param,
						int *nb_space, int *size_str);
void					ft_parse_options(t_data data, char *param,
						size_t *total);

void					ft_init_str(char str[], int nb);
void					ft_div_str(char str[]);
void					ft_mult_str(char str[], int exp);
void					ft_strmove(char nbr[]);
void					ft_strmove2(char nbr[]);

void					ft_incrementation_nbr(char nbr[], int j, int i);
void					ft_add_str(char nbr[], char str[]);
void					ft_strcpy(char str[], char str2[]);

void					ft_int_to_bin(char str[65], double f);
int						ft_exp_to_int(char bin[65]);
void					ft_precision_float(char nbr[], int precision);
void					ft_create_nbr(char nbr[], char str[], char bin[],
						int neg);
char					*ft_float(double n, char nbr[], t_data data);

int						ft_usage(const char *str);

#endif
