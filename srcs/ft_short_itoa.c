/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:47:58 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/03 15:48:23 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_short_size_nb(short int n)
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

char		*ft_short_itoa(short int n)
{
	char			*str;
	short int		size_nb;
	int				neg;

	neg = (n < 0) ? -1 : 0;
	size_nb = get_short_size_nb(n);
	if (!(str = (char *)malloc(sizeof(char) * (size_nb + 1))))
		return (NULL);
	str[size_nb--] = '\0';
	while (size_nb >= 0)
	{
		str[size_nb--] = (n < 0) ? (n % 10) * -1 + '0' : n % 10 + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

static int	get_unsigned_short_size_nb(unsigned short int n)
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

char		*ft_unsigned_short_itoa(unsigned short int n)
{
	char		*str;
	short int	size_nb;

	size_nb = get_unsigned_short_size_nb(n);
	if (!(str = (char *)malloc(sizeof(char) * (size_nb + 1))))
		return (NULL);
	str[size_nb--] = '\0';
	while (size_nb >= 0)
	{
		str[size_nb--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
