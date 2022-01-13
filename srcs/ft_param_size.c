/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:29:48 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/13 10:55:56 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdarg.h>

char	*ft_param_no_size(va_list ap, t_data data, char tab[])
{
	if (data.type == 'u')
		return (ft_itoa(va_arg(ap, unsigned int), tab));
	else if (data.type == 'p')
		return (ft_unsigned_itoa(va_arg(ap, unsigned long long int), tab));
	else if (data.type == 'c')
		return (ft_char_to_str(va_arg(ap, int), tab));
	else if (data.type == '%')
		return (ft_char_to_str('%', tab));
	else if (data.type == 'd' || data.type == 'i')
		return (ft_itoa(va_arg(ap, int), tab));
	else if (data.type == 'f')
		return (ft_float(va_arg(ap, double), tab, data));
	else if (data.type != 's')
		return (ft_itoa(va_arg(ap, unsigned int), tab));
	else
		return (va_arg(ap, char *));
}

char	*ft_param_size_l(va_list ap, t_data data, char tab[])
{
	if (data.type == 'u')
		return (ft_unsigned_itoa(va_arg(ap, unsigned long long int), tab));
	else if (data.type == 'p')
		return (ft_unsigned_itoa(va_arg(ap, unsigned long long int), tab));
	else if (data.type == 'c')
		return (ft_char_to_str(va_arg(ap, unsigned long long int), tab));
	else if (data.type == '%')
		return (ft_char_to_str('%', tab));
	else if (data.type == 'd' || data.type == 'i')
		return (ft_itoa(va_arg(ap, long long int), tab));
	else if (data.type == 'f')
		return (ft_float(va_arg(ap, double), tab, data));
	else if (data.type != 's')
		return (ft_itoa(va_arg(ap, unsigned long long int), tab));
	else
		return (va_arg(ap, char *));
}

char	*ft_param_size_h(va_list ap, t_data data, char tab[])
{
	if (data.type == 'p')
		return (ft_unsigned_itoa(va_arg(ap, unsigned long long int), tab));
	else if (data.type == 'c')
		return (ft_char_to_str(va_arg(ap, unsigned long long int), tab));
	else if (data.type == '%')
		return (ft_char_to_str('%', tab));
	else if (data.type == 'd' || data.type == 'i')
		return (ft_short_itoa(va_arg(ap, unsigned long long int), tab));
	else if (data.type == 'f')
		return (ft_float(va_arg(ap, double), tab, data));
	else if (data.type != 's')
		return (ft_unsigned_short_itoa(va_arg(ap,
						unsigned long long int), tab));
	else
		return (va_arg(ap, char *));
}

char	*ft_param_size_hh(va_list ap, t_data data, char tab[])
{
	if (data.type == 'p')
		return (ft_unsigned_itoa(va_arg(ap, unsigned long long int), tab));
	else if (data.type == 'c')
		return (ft_char_to_str(va_arg(ap, unsigned long long int), tab));
	else if (data.type == '%')
		return (ft_char_to_str('%', tab));
	else if (data.type == 'd' || data.type == 'i')
		return (ft_char_itoa(va_arg(ap, unsigned long long int), tab));
	else if (data.type == 'f')
		return (ft_float(va_arg(ap, double), tab, data));
	else if (data.type != 's')
		return (ft_unsigned_char_itoa(va_arg(ap, unsigned long long int), tab));
	else
		return (va_arg(ap, char *));
}
