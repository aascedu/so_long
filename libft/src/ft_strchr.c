/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:41:34 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/21 09:41:30 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c == 0)
		return ((char *)s + (int)ft_strlen(s));
	i = 0;
	while ((unsigned char)c != s[i] && s[i])
		i++;
	if (s[i] == 0)
		return (NULL);
	else
		return ((char *)s + i);
}
