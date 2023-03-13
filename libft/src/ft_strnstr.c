/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:03:18 by aascedu           #+#    #+#             */
/*   Updated: 2022/11/22 08:37:28 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_needlematch(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && needle[i] && haystack[i] == needle[i])
		i++;
	if (needle[i] == 0)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i])
	{
		if (haystack[i] == needle[0])
			if (ft_needlematch(&haystack[i], needle, len - i) == 1)
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
