/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trlevequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:36:20 by trlevequ          #+#    #+#             */
/*   Updated: 2018/11/28 15:39:49 by trlevequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

void	ft_putnstr(char const *s, size_t n)
{
	write(1, s, n);
}
