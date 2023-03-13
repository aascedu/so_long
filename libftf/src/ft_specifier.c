/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:41:08 by aascedu           #+#    #+#             */
/*   Updated: 2022/12/05 13:44:33 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isformat(int c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's' || c == 'p' || c == 'x'
		|| c == 'X' || c == 'u' || c == '%')
		return (1);
	return (0);
}

int	ft_specifier(va_list ap, const char c)
{
	int	length;

	length = 0;
	if (c == 'd' || c == 'i')
		length += ft_print_nbr(va_arg(ap, int));
	if (c == 'c')
		length += ft_print_char(va_arg(ap, int));
	else if (c == 's')
		length += ft_print_str(va_arg(ap, char *));
	else if (c == 'p')
		length += ft_print_addr(va_arg(ap, unsigned long long));
	else if (c == 'x' || c == 'X')
		length += ft_print_hex(va_arg(ap, unsigned int), c);
	else if (c == 'u')
		length += ft_print_unbr(va_arg(ap, unsigned int));
	else if (c == '%')
		length += ft_print_char('%');
	else if (!ft_isformat(c))
		length += ft_print_char(c);
	return (length);
}
