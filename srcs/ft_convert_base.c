/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:20:13 by trlevequ          #+#    #+#             */
/*   Updated: 2018/12/13 15:53:39 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_convert_base(unsigned long long int nb, char *str)
{
	unsigned long long int	len;

	len = ft_strlen(str);
	if (nb >= len)
		ft_convert_base(nb / len, str);
	ft_putchar(str[(nb % len)]);
}

void	ft_long_convert_base(unsigned long long int nb, char *str)
{
	unsigned long long int	len;
	unsigned long long int	n;

	if (nb <= 4294967296)
	{
		ft_convert_base(nb, str);
		return ;
	}
	else
		n = nb;
	len = ft_strlen(str);
	if (n >= len)
		ft_long_convert_base(n / len, str);
	ft_putchar(str[(n % len)]);
}

int		ft_count_base(unsigned long long int nb, char *str)
{
	long long int	len;
	int				i;

	len = ft_strlen(str);
	i = (nb == 0) ? 1 : 0;
	while (nb != 0)
	{
		nb /= len;
		i++;
	}
	return (i);
}

int		ft_unsigned_count_base(unsigned long long nb, char *str)
{
	unsigned long long int	len;
	unsigned long long int	n;
	int						i;

	if (nb <= 4294967296)
		return (ft_count_base(nb, str));
	else
		n = nb;
	len = ft_strlen(str);
	i = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= len;
		i++;
	}
	return (i);
}
