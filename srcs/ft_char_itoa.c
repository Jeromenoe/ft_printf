/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:46:29 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/12 18:47:00 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_char_size_nb(char n)
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

char		*ft_char_itoa(char n, char tab[])
{
	int				size_nb;
	int				neg;

	neg = (n < 0) ? -1 : 0;
	size_nb = get_char_size_nb(n);
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

static int	get_unsigned_char_size_nb(unsigned char n)
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

char		*ft_unsigned_char_itoa(unsigned char n, char tab[])
{
	int				size_nb;

	size_nb = get_unsigned_char_size_nb(n);
	tab[size_nb--] = '\0';
	while (size_nb >= 0)
	{
		tab[size_nb--] = n % 10 + '0';
		n /= 10;
	}
	return (tab);
}
