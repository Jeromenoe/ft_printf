/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:57:02 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/13 15:13:30 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_exit(void)
{
	ft_putstr("usage: ft_printf(\"%[flags][width][.precision][size]type\"");
	ft_putstr(", arg)\n");
	ft_putstr("       flags: '-' '+' ' ' '#' '0'\n");
	ft_putstr("       width: int\n");
	ft_putstr("       precision: int\n");
	ft_putstr("       size: 'h' 'hh' 'l' 'll' 'L' 'j'\n");
	ft_putstr("       type: 'c' 's' 'p' 'd' 'i' 'o' 'u' 'x' 'X' 'f' '%'\n");
	return (0);
}

void	ft_usage_condition(const char *str, int *i)
{
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
			(*i)++;
	}
	if (str[*i] == 'h' && str[*i + 1] == 'h')
		*i += 2;
	else if (str[*i] == 'h')
		(*i)++;
	else if (str[*i] == 'l' && str[*i + 1] == 'l')
		*i += 2;
	else if (str[*i] == 'l' || str[*i] == 'j')
		(*i)++;
	else if (str[*i] == 'L')
		(*i)++;
}

int		ft_usage(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] && (str[i] == '+' || str[i] == ' ' || str[i] == '#'
						|| str[i] == '-' || str[i] == '0'))
				i++;
			ft_usage_condition(str, &i);
			if (str[i] == 'c' || str[i] == 's' || str[i] == 'p'
					|| str[i] == 'd' || str[i] == 'i' || str[i] == 'o'
					|| str[i] == 'u' || str[i] == 'x' || str[i] == 'X'
					|| str[i] == 'f' || str[i] == '%')
				i++;
			else
				return (ft_exit());
		}
		else
			i++;
	}
	return (1);
}
