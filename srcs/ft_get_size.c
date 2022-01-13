/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:10:09 by trlevequ          #+#    #+#             */
/*   Updated: 2018/12/13 14:43:03 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	get_precision(t_data *data, char *param)
{
	if (data->type != 'f' && ft_atoi(param) < 0 && data->precision > 0)
		data->precision++;
	if (data->type == 'c' || data->type == '%')
		data->precision = 0;
}

void	get_size_str(t_data *data, char *param, int *size_str)
{
	int i;

	if (data->type == 's')
		*size_str = (data->precision < data->len_param && data->precision != -1)
			? data->precision : data->len_param;
	else if (data->type == 'f')
	{
		i = 0;
		while (param[i] != '.' && param[i] != '\0')
			i++;
		if (param[i] == '.')
			i++;
		*size_str = data->precision + i;
	}
	else
		*size_str = (data->precision > data->len_param) ? data->precision \
					: data->len_param;
	if (data->type == 'c' && param[0] == 0)
		*size_str += 1;
	if (!data->precision && data->type != 's' && data->type != 'c'\
			&& data->type != '%' && !ft_atoi(param) && data->type != 'f')
		*size_str = 0;
}

void	get_nb_space(t_data *data, char *param, int *size_str, int *nb_space)
{
	*nb_space = (data->width > *size_str) ? data->width - *size_str \
				- get_if_space(*data, param) - get_if_plus(*data, param) \
				- get_if_hashtag(*data, param) : 0;
	if (*nb_space < 0)
		*nb_space = 0;
	if (get_if_space(*data, param))
		ft_putchar(' ');
}
