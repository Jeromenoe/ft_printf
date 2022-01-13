/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:12:37 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/13 16:52:13 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_fill_type(const char **format, t_data *data)
{
	if (**format == 'c' || **format == 's' || **format == 'p'
			|| **format == 'd' || **format == 'i' || **format == 'o'
			|| **format == 'u' || **format == 'x' || **format == 'X'
			|| **format == 'f' || **format == '%')
	{
		data->type = **format;
		++(*format);
	}
	if (data->type == 'f' && data->precision == -1)
		data->precision = 6;
}

void	ft_fill_data_len_param(t_data *data, char *param)
{
	if (data->type == 'o')
		data->len_param = ft_unsigned_count_base(ft_atoi(param), "01234567");
	else if (data->type == 'x')
		data->len_param =
			ft_unsigned_count_base(ft_atoi(param), "0123456789abcdef");
	else if (data->type == 'X')
		data->len_param =
			ft_unsigned_count_base(ft_atoi(param), "0123456789ABCDEF");
	else if (data->type == 'p')
		data->len_param =
			ft_unsigned_count_base(ft_unsigned_atoi(param), "0123456789abcdef");
	else
		data->len_param = ft_strlen(param);
}

t_data	ft_fill_data(const char **format)
{
	t_data data;

	ft_init_data(&data);
	ft_fill_flags(format, &data);
	ft_fill_width(format, &data);
	ft_fill_precision(format, &data);
	ft_fill_size(format, &data);
	ft_fill_type(format, &data);
	return (data);
}
