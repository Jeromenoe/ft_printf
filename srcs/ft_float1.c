/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:11:32 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/12 19:06:46 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_init_str(char str[], int nb)
{
	int i;

	i = -1;
	while (++i < nb)
		str[i] = '0';
	str[i] = '\0';
}

void	ft_div_str(char str[])
{
	int	i;

	i = (int)ft_strlen(str);
	while (--i >= 0)
	{
		if (str[i] != '0')
		{
			if (str[i] % 2 == 1)
			{
				if (i == (int)(ft_strlen(str) - 1))
				{
					str[i + 2] = '\0';
					str[i + 1] = '0';
				}
				str[i + 1] += 5;
			}
			str[i] = (str[i] - '0') / 2 + '0';
		}
	}
}

void	ft_mult_str(char str[], int exp)
{
	int		i;
	char	scpy[311];

	ft_init_str(str, 310);
	str[0] = '1';
	str[1] = '\0';
	i = 0;
	while (++i <= exp)
	{
		ft_strcpy(str, scpy);
		ft_add_str(str, scpy);
	}
	while (--i > exp)
		ft_div_str(str);
}

void	ft_strmove(char nbr[])
{
	int i;

	i = 309;
	while (--i >= 0)
		nbr[i + 1] = nbr[i];
	nbr[0] = '0';
}

void	ft_strmove2(char nbr[])
{
	int i;

	i = ft_strlen(nbr);
	nbr[i] = '0';
	nbr[i + 1] = '\0';
}
