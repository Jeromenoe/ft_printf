/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:55:57 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/13 16:52:31 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_int_to_bin(char str[65], double f)
{
	long	nb;
	int		i;

	nb = *(long *)&f;
	i = 64;
	str[i--] = '\0';
	while (i)
	{
		str[i--] = nb % 2 + '0';
		nb /= 2;
	}
	str[i] = (nb < 0 ? '1' : '0');
}

int		ft_exp_to_int(char bin[65])
{
	int		nbr;
	int		i;
	int		pow;

	i = 12;
	pow = 1;
	nbr = 0;
	while (--i > 0)
	{
		if (bin[i] == '1')
			nbr = nbr + pow;
		pow *= 2;
	}
	return (nbr - 1023);
}

void	ft_create_nbr(char nbr[], char str[], char bin[], int neg)
{
	int i;
	int exp;

	exp = (neg == -1) ? ft_exp_to_int(bin) : 1;
	i = 11;
	while (++i < 64)
	{
		ft_div_str(str);
		if (exp == 0)
		{
			(neg < 0) ? ft_strmove2(nbr) : ft_strmove(nbr);
			ft_strmove(str);
			if (neg > 0 && nbr[0] == '-')
				nbr[2] = '.';
			else if (neg > 0)
				nbr[1] = '.';
			else
				nbr[ft_strlen(nbr) - 1] = '.';
		}
		while (ft_strlen(nbr) != ft_strlen(str))
			(ft_strlen(nbr) > ft_strlen(str)) \
				? ft_strmove(str) : ft_strmove2(nbr);
		(bin[i] - '0') ? ft_add_str(nbr, str) : 0;
		exp -= 1;
	}
}

void	ft_loop_precision(char nbr[], int k)
{
	while (nbr[--k] > '9')
	{
		if (k == 0)
		{
			ft_strmove(nbr);
			k = 1;
		}
		nbr[k] = (nbr[k] - '0') % 10 + '0';
		if (nbr[k - 1] == '.')
			k--;
		nbr[k - 1] += 1;
	}
}

void	ft_precision_float(char nbr[], int precision)
{
	int j;
	int k;

	j = 0;
	precision = (precision > (int)ft_strlen(nbr)) ? \
				ft_strlen(nbr) - 1 : precision;
	while (nbr[j] != '.' && nbr[j] != '\0')
		++j;
	if (nbr[j] == '\0')
		precision = 0;
	precision += j;
	if (precision != j && nbr[precision] && nbr[precision + 1] >= '5')
		nbr[precision] += 1;
	else if (precision == j && nbr[precision + 1] >= '5')
		nbr[precision - 1] += 1;
	nbr[j] = (precision == j) ? '\0' : nbr[j];
	k = (precision == j) ? precision : precision + 1;
	nbr[precision + 1] = '\0';
	ft_loop_precision(nbr, k);
}
