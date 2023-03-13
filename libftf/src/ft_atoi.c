/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:07:49 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/18 10:28:33 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	number;

	i = 0;
	while (ft_whitespace(str[i]) == 1)
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	number = 0;
	while (ft_isdigit(str[i]))
	{
		if (number != ((number * 10) + (str[i] - 48)) / 10)
			return ((sign + 1) / -2);
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return ((sign * number));
}
