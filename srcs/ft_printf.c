/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:11:21 by trlevequ          #+#    #+#             */
/*   Updated: 2018/12/13 15:54:51 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "printf.h"

char	*ft_get_param(va_list ap, t_data data, char tab[])
{
	if (!data.size)
		return (ft_param_no_size(ap, data, tab));
	else if (data.l || data.ll || data.j)
		return (ft_param_size_l(ap, data, tab));
	else if (data.h)
		return (ft_param_size_h(ap, data, tab));
	else if (data.hh)
		return (ft_param_size_hh(ap, data, tab));
	else
		return (va_arg(ap, char *));
}

char	*ft_alloc_for_null(char tab[])
{
	tab[0] = '(';
	tab[1] = 'n';
	tab[2] = 'u';
	tab[3] = 'l';
	tab[4] = 'l';
	tab[5] = ')';
	tab[6] = '\0';
	return (tab);
}

void	ft_get_format(const char **format, va_list ap, size_t *total)
{
	t_data	data;
	char	*param;
	char	tab[311];

	++(*format);
	data = ft_fill_data(format);
	param = ft_get_param(ap, data, tab);
	if (!param && data.type)
		param = ft_alloc_for_null(tab);
	if (data.type)
	{
		ft_fill_data_len_param(&data, param);
		ft_parse_options(data, param, total);
	}
}

int		ft_printf(const char *format, ...)
{
	va_list				ap;
	size_t				total;
	unsigned long long	len;

	if (!(ft_usage(format)))
		return (0);
	total = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			ft_get_format(&format, ap, &total);
		else
		{
			len = ft_strclen(format);
			ft_putnstr(format, len);
			total += len;
			format = format + len;
		}
	}
	va_end(ap);
	return ((int)total);
}
