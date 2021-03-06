/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:49:51 by rsanchez          #+#    #+#             */
/*   Updated: 2020/12/15 14:49:53 by rsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*substr_free(char *str, size_t start, size_t len, int freestr)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (str && str[i])
		i++;
	if (!str || i < start)
	{
		if (!(temp = malloc(sizeof(char))))
			return (NULL);
		temp[0] = '\0';
		return (temp);
	}
	if (i < start + len)
		len = i - start;
	if (!(temp = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		temp[i] = str[start + i];
	temp[i] = '\0';
	if (str && freestr)
		free(str);
	return (temp);
}

char	*join_free(char *str1, char *str2, int freestr1, int freestr2)
{
	size_t	i;
	size_t	i2;
	char	*temp;

	i = 0;
	i2 = 0;
	while (str1 && str1[i])
		i++;
	while (str2 && str2[i2])
		i2++;
	if (!(temp = malloc(sizeof(char) * (i + i2 + 1))))
		return (NULL);
	temp[i + i2] = '\0';
	while (i2-- > 0)
		temp[i + i2] = str2[i2];
	while (i-- > 0)
		temp[i] = str1[i];
	if (str1 && freestr1)
		free(str1);
	if (str2 && freestr2)
		free(str2);
	return (temp);
}
