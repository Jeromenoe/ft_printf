/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:15:29 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/12 19:06:25 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_incrementation_nbr(char nbr[], int j, int i)
{
	while (--j >= 0 && nbr[j] > '9')
	{
		if (j == 0)
		{
			ft_strmove(nbr);
			nbr[i] += 1;
		}
		nbr[j - 1] += 1;
		nbr[j] = '0';
	}
}

void	ft_add_str(char nbr[], char str[])
{
	int i;

	i = ft_strlen(nbr);
	while (--i >= 0)
	{
		if (nbr[i] + str[i] - '0' > '9')
		{
			nbr[i] = (nbr[i] - '0' + str[i] - '0') % 10 + '0';
			if (i == 0)
			{
				ft_strmove(nbr);
				nbr[i] += 1;
			}
			else
				nbr[i - 1] += 1;
			ft_incrementation_nbr(nbr, i + 1, i);
		}
		else
			nbr[i] = nbr[i] + str[i] - '0';
	}
}

void	ft_strcpy(char str[], char str2[])
{
	int i;

	i = -1;
	while (str[++i])
		str2[i] = str[i];
	str2[i] = '\0';
}

void	ft_sign(char nbr[], char str[], char bin[], int sign)
{
	int neg;

	neg = (ft_exp_to_int(bin) >= 0) ? -1 : 1;
	if (sign == -1)
	{
		ft_strmove(nbr);
		ft_strmove(str);
	}
	ft_create_nbr(nbr, str, bin, neg);
	if (nbr[0] != '0' && sign == -1)
		ft_strmove(nbr);
	if (sign == -1)
		nbr[0] = '-';
	if (nbr[1] == '.' && sign == -1)
	{
		nbr[1] = '0';
		nbr[2] = '.';
	}
}

char	*ft_float(double n, char nbr[], t_data data)
{
	char	str[311];
	char	bin[65];
	int		exp;
	int		sign;

	if (n != 0)
	{
		ft_init_str(nbr, 310);
		sign = (n < 0.0) ? -1 : 0;
		n = (n < 0.0) ? -n : n;
		ft_int_to_bin(bin, n);
		exp = ft_exp_to_int(bin);
		ft_mult_str(str, exp);
		ft_strcpy(str, nbr);
		ft_sign(nbr, str, bin, sign);
	}
	else
		ft_strcpy("0", nbr);
	ft_precision_float(nbr, data.precision);
	return (nbr);
}
