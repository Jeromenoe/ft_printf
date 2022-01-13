/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoe <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:49:04 by jnoe              #+#    #+#             */
/*   Updated: 2018/12/13 14:29:57 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_if_plus(t_data data, char *param)
{
	if ((data.type == 'd' || data.type == 'i') && data.plus)
	{
		if (ft_atoi(param) >= 0)
			return (1);
	}
	else if ((data.type == 'f') && data.plus)
	{
		if (param[0] != '-')
			return (1);
	}
	return (0);
}

int		get_if_space(t_data data, char *param)
{
	long long nb;

	if ((data.type == 'd' || data.type == 'i')
			&& data.space && !get_if_plus(data, param))
	{
		nb = ft_atoi(param);
		if (nb >= 0)
			return (1);
	}
	else if ((data.type == 'f') && data.space
			&& !get_if_plus(data, param))
	{
		if (param[0] != '-')
			return (1);
	}
	return (0);
}

int		get_if_hashtag(t_data data, char *param)
{
	if (data.type == 'p')
		return (2);
	if (!data.hashtag)
		return (0);
	if (ft_atoi(param) == 0 && data.type != 'o')
		return (0);
	if (data.type == 'o' && data.precision == 0)
		return (1);
	if (data.type == 'o' && data.precision == -1 && ft_atoi(param) != 0)
		return (1);
	if (data.type == 'x' || data.type == 'X')
		return (2);
	return (0);
}

void	put_if_hashtag(t_data data)
{
	if (data.type == 'o')
		ft_putchar('0');
	else if (data.type == 'x' || data.type == 'p')
		ft_putstr("0x");
	else if (data.type == 'X')
		ft_putstr("0X");
}
