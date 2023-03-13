/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:15:00 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/16 15:53:23 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	begin_len_base;

	if (!dstsize && (!src || !dst))
		return (0);
	begin_len_base = ft_strlen(dst);
	i = begin_len_base;
	if (begin_len_base >= dstsize)
		return (dstsize + ft_strlen(src));
	k = 0;
	while (i < dstsize - 1 && src[k])
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (begin_len_base + ft_strlen(src));
}
