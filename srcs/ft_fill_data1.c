/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:51:40 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/13 17:18:21 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_init_data(t_data *data)
{
	data->minus = 0;
	data->plus = 0;
	data->space = 0;
	data->zero = 0;
	data->hashtag = 0;
	data->width = 0;
	data->precision = -1;
	data->size = 0;
	data->hh = 0;
	data->h = 0;
	data->ll = 0;
	data->l = 0;
	data->j = 0;
	data->len_param = 0;
	data->type = '\0';
}

void	ft_fill_flags(const char **format, t_data *data)
{
	while (**format == '-' || **format == '+' || **format == ' '
			|| **format == '0' || **format == '#')
	{
		if (**format == '-')
			data->minus = 1;
		else if (**format == '+')
			data->plus = 1;
		else if (**format == ' ')
			data->space = 1;
		else if (**format == '0')
			data->zero = 1;
		else if (**format == '#')
			data->hashtag = 1;
		++(*format);
	}
}

void	ft_fill_width(const char **format, t_data *data)
{
	data->width = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		++(*format);
}

void	ft_fill_precision(const char **format, t_data *data)
{
	if (**format == '.')
	{
		data->precision = 0;
		++(*format);
		data->precision = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			++(*format);
	}
}

void	ft_fill_size(const char **format, t_data *data)
{
	if (**format == 'h' && *(*format + 1) == 'h' && (data->size = 1))
	{
		data->hh = 1;
		(*format) += 2;
	}
	else if (**format == 'h' && (data->size = 1))
	{
		data->h = 1;
		++(*format);
	}
	else if (**format == 'l' && *(*format + 1) == 'l' && (data->size = 1))
	{
		data->ll = 1;
		(*format) += 2;
	}
	else if ((**format == 'l' || **format == 'j' || **format == 'L')\
		&& (data->size = 1))
	{
		data->l = 1;
		++(*format);
	}
}
