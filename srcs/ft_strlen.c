/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:31:16 by trlevequ          #+#    #+#             */
/*   Updated: 2018/12/03 16:45:34 by jnoe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t				ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		++str;
		++i;
	}
	return (i);
}

unsigned long long	ft_strclen(const char *str)
{
	unsigned long long i;

	i = 0;
	while (str[i] && str[i] != '%')
		++i;
	return (i);
}
