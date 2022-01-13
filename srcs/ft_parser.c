/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:07:10 by trlevequ          #+#    #+#             */
/*   Updated: 2018/12/13 16:52:48 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_if_minus(t_data *data, char *param, int *nb_space)
{
	int check;

	check = 0;
	if (data->zero && (data->type == 's' || data->precision == -1 \
				|| data->precision == 0))
	{
		if (get_if_plus(*data, param))
			ft_putchar('+');
		else if (ft_atoi(param) < 0 && (check = 1))
			ft_putchar('-');
		if (get_if_hashtag(*data, param))
			put_if_hashtag(*data);
		ft_putnchar('0', *nb_space);
	}
	else
	{
		ft_putnchar(' ', *nb_space);
		if (get_if_plus(*data, param))
			ft_putchar('+');
		if (get_if_hashtag(*data, param))
			put_if_hashtag(*data);
	}
	return (check);
}

int		print_before_param(t_data *data, char *param, int *nb_space)
{
	int check;

	if (!data->minus)
		check = print_if_minus(data, param, nb_space);
	else
	{
		if (get_if_hashtag(*data, param))
			put_if_hashtag(*data);
	}
	if (get_if_plus(*data, param) && data->minus)
		ft_putchar('+');
	if (data->type != 'f' && ft_atoi(param) < 0 && data->precision > 0)
	{
		check = 1;
		ft_putchar('-');
	}
	if (data->type != 's' && data->type != 'f' \
			&& data->precision > data->len_param)
		ft_putnchar('0', data->precision - data->len_param);
	return (check);
}

int		ft_before_param(t_data *data, char *param, int *nb_space, int *size_str)
{
	int check;

	check = 0;
	*size_str = 0;
	get_precision(data, param);
	get_size_str(data, param, size_str);
	get_nb_space(data, param, size_str, nb_space);
	check = print_before_param(data, param, nb_space);
	return (check);
}

int		ft_manage_float(t_data data, char *param)
{
	int	nb_precision;
	int i;

	i = 0;
	nb_precision = 0;
	while (param[i] && param[i] != '.')
		++i;
	if (!data.precision)
		return (0);
	(param[i] != '.') ? ft_putchar('.') : ++i;
	while (param[i])
	{
		++nb_precision;
		++i;
	}
	ft_putnchar('0', data.precision - nb_precision);
	return (0);
}

void	ft_parse_options(t_data data, char *param, size_t *total)
{
	int		nb_space;
	int		size_str;
	int		check;

	check = ft_before_param(&data, param, &nb_space, &size_str);
	if (size_str)
	{
		if (check == 1)
			ft_print_param(data, param + 1, size_str - 1);
		else
			ft_print_param(data, param, size_str);
	}
	if (data.minus)
		ft_putnchar(' ', nb_space);
	if (data.type == 'f')
		ft_manage_float(data, param);
	*total += size_str + nb_space + get_if_space(data, param) \
			+ get_if_plus(data, param) + get_if_hashtag(data, param);
}
