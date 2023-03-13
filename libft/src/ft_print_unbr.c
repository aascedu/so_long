/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:41:01 by aascedu           #+#    #+#             */
/*   Updated: 2022/12/05 13:44:47 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_unbr(unsigned int n, int *length)
{
	if (n > 9)
	{
		ft_put_unbr(n / 10, length);
		ft_putchar_fd((n % 10) + 48, 1);
		*length += 1;
	}
	else
	{
		ft_putchar_fd(n + 48, 1);
		*length += 1;
	}
}

int	ft_print_unbr(unsigned int unbr)
{
	int	length;

	length = 0;
	ft_put_unbr(unbr, &length);
	return (length);
}
