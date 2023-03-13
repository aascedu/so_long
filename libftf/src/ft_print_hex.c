/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:40:46 by aascedu           #+#    #+#             */
/*   Updated: 2022/12/05 13:45:04 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_hex_upper(unsigned int nbr, int *length)
{
	if (nbr >= 16)
	{
		ft_hex_upper(nbr / 16, length);
		ft_hex_upper(nbr % 16, length);
	}
	else
	{
		if (nbr >= 0 && nbr <= 9)
			*length += ft_print_char(nbr + 48);
		else
			*length += ft_print_char(nbr + 'A' - 10);
	}
}

static void	ft_hex_lower(unsigned int nbr, int *length)
{
	if (nbr >= 16)
	{
		ft_hex_lower(nbr / 16, length);
		ft_hex_lower(nbr % 16, length);
	}
	else
	{
		if (nbr >= 0 && nbr <= 9)
			*length += ft_print_char(nbr + 48);
		else
			*length += ft_print_char(nbr + 'a' - 10);
	}
}

int	ft_print_hex(unsigned int nbr, const char c)
{
	int	length;

	length = 0;
	if (nbr == 0)
		length += ft_print_char('0');
	else
	{
		if (c == 'X')
			ft_hex_upper(nbr, &length);
		else if (c == 'x')
			ft_hex_lower(nbr, &length);
	}
	return (length);
}
