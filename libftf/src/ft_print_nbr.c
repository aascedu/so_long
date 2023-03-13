/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:40:50 by aascedu           #+#    #+#             */
/*   Updated: 2022/12/05 13:45:01 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_nbr(int n, int *length)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*length += 11;
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_put_nbr(n * -1, length);
		*length += 1;
	}
	else if (n > 9)
	{
		ft_put_nbr(n / 10, length);
		ft_putchar_fd((n % 10) + 48, 1);
		*length += 1;
	}
	else
	{
		ft_putchar_fd(n + 48, 1);
		*length += 1;
	}
}

int	ft_print_nbr(int nbr)
{
	int	length;

	length = 0;
	ft_put_nbr(nbr, &length);
	return (length);
}
