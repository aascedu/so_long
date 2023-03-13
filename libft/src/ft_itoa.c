/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:41:47 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/22 08:36:37 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n, int sign)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	if (sign == -1)
		i++;
	return (++i);
}

static char	*ft_revstr(char *str)
{
	int		i;
	int		size;
	char	temp;

	i = 0;
	size = (int)ft_strlen(str);
	while (i < (size / 2))
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		sign;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 1;
	if (n < 0)
		sign = -1;
	if (n < 0)
		n = n * -1;
	res = (char *)malloc(sizeof(char) * (ft_size(n, sign) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (n >= 10)
	{
		res[i++] = "0123456789"[n % 10];
		n = n / 10;
	}
	res[i++] = "0123456789"[n];
	if (sign == -1)
		res[i++] = '-';
	res[i] = '\0';
	return (ft_revstr(res));
}
