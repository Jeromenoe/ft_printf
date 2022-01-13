/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:17:32 by trlevequ          #+#    #+#             */
/*   Updated: 2018/12/03 09:49:17 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int			ft_atoi(const char *str)
{
	int				neg;
	long long int	nb;

	nb = 0;
	neg = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' \
			|| *str == '\f' || *str == ' ')
		++str;
	if (*str == '-' || *str == '+')
		neg = (*str++ == '-') ? -1 : 1;
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + ((*str++ - '0') * neg);
	return (nb);
}

unsigned long long int	ft_unsigned_atoi(const char *str)
{
	unsigned long long int	nb;

	nb = 0;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v' \
			|| *str == '\f' || *str == ' ')
		++str;
	while (*str >= '0' && *str <= '9')
		nb = (nb * 10) + (*str++ - '0');
	return (nb);
}
