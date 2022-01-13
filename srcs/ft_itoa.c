/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:48:27 by trlevequ          #+#    #+#             */
/*   Updated: 2018/12/12 18:47:52 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_size_nb(long long int n)
{
	int size;

	size = 0;
	if (n <= 0)
		++size;
	while (n)
	{
		n /= 10;
		++size;
	}
	return (size);
}

char		*ft_itoa(long long int n, char tab[])
{
	int				size_nb;
	int				neg;

	neg = (n < 0) ? -1 : 0;
	size_nb = get_size_nb(n);
	tab[size_nb--] = '\0';
	while (size_nb >= 0)
	{
		tab[size_nb--] = (n < 0) ? (n % 10) * -1 + '0' : n % 10 + '0';
		n /= 10;
	}
	if (neg)
		tab[0] = '-';
	return (tab);
}

static int	get_size_unsigned_nb(unsigned long long int n)
{
	int size;

	size = 0;
	if (n <= 0)
		++size;
	while (n)
	{
		n /= 10;
		++size;
	}
	return (size);
}

char		*ft_unsigned_itoa(unsigned long long int n, char tab[])
{
	int			size_nb;

	size_nb = get_size_unsigned_nb(n);
	tab[size_nb--] = '\0';
	while (size_nb >= 0)
	{
		tab[size_nb--] = n % 10 + '0';
		n /= 10;
	}
	return (tab);
}
