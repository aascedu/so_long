/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:40:38 by aascedu           #+#    #+#             */
/*   Updated: 2022/12/05 13:45:12 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_hex_print(unsigned long long ptr, int *length)
{
	if (ptr >= 16)
	{
		ft_hex_print(ptr / 16, length);
		ft_hex_print(ptr % 16, length);
	}
	else
	{
		if (ptr >= 0 && ptr <= 9)
			*length += ft_print_char(ptr + 48);
		else
			*length += ft_print_char(ptr + 'a' - 10);
	}
}

int	ft_print_addr(unsigned long long ptr)
{
	int		length;

	length = 0;
	length += ft_print_str("0x");
	if (!ptr)
		length += ft_print_char('0');
	else
		ft_hex_print(ptr, &length);
	return (length);
}
