/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_frees1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aascedu <aascedu@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:26:21 by aascedu           #+#    #+#             */
/*   Updated: 2023/03/13 15:09:36 by aascedu          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_frees1(char *temp, char *line)
{
	char	*result;
	int		line_len;
	int		temp_len;
	int		i;

	line_len = ft_strlen(line);
	temp_len = ft_strlen(temp);
	result = (char *)malloc(sizeof(char) * (line_len + temp_len + 1));
	if (!result)
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (line[++i])
		result[i] = line[i];
	i = -1;
	while (temp[++i])
		result[line_len + i] = temp[i];
	result[line_len + temp_len] = '\0';
	free(temp);
	return (result);
}
