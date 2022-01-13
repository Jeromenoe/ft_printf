/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:38:39 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/13 10:54:07 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_param_no_size(t_data data, char *param, int size_param)
{
	if (data.type == 'd' || data.type == 'i' || data.type == 'f')
		ft_putstr(param);
	else if (data.type == 'o')
		ft_convert_base(ft_atoi(param), "01234567");
	else if (data.type == 'u')
		ft_putstr(param);
	else if (data.type == 'x')
		ft_convert_base(ft_atoi(param), "0123456789abcdef");
	else if (data.type == 'X')
		ft_convert_base(ft_atoi(param), "0123456789ABCDEF");
	else if (data.type == 'p')
		ft_convert_base(ft_unsigned_atoi(param), "0123456789abcdef");
	else if (data.type == 'c')
		ft_putnstr(param, 1);
	else if (data.type == '%')
		ft_putnstr(param, 1);
	else if (data.type == 's')
		ft_putnstr(param, size_param);
}

void	ft_print_param_size_l(t_data data, char *param, int size_param)
{
	if (data.type == 'd' || data.type == 'i' || data.type == 'f')
		ft_putstr(param);
	else if (data.type == 'o')
		ft_long_convert_base(ft_atoi(param), "01234567");
	else if (data.type == 'u')
		ft_putstr(param);
	else if (data.type == 'x')
		ft_long_convert_base(ft_atoi(param), "0123456789abcdef");
	else if (data.type == 'X')
		ft_long_convert_base(ft_atoi(param), "0123456789ABCDEF");
	else if (data.type == 'p')
		ft_long_convert_base(ft_unsigned_atoi(param), "0123456789abcdef");
	else if (data.type == 'c')
		ft_putnstr(param, 1);
	else if (data.type == '%')
		ft_putnstr(param, 1);
	else if (data.type == 's')
		ft_putnstr(param, size_param);
}

void	ft_print_param(t_data data, char *param, int size_param)
{
	if (!data.size)
		ft_print_param_no_size(data, param, size_param);
	else if (data.l || data.ll || data.j)
		ft_print_param_size_l(data, param, size_param);
	else if (data.h)
		ft_print_param_size_l(data, param, size_param);
	else if (data.hh)
		ft_print_param_size_l(data, param, size_param);
}
