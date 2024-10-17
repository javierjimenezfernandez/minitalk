/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:26:22 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/06 13:19:15 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_compute_trimmed_size(char const *s1, char const *set)
{
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	size = ft_strlen(s1) + 1;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]))
			size--;
		else
			break ;
		i++;
	}
	j = ft_strlen(s1);
	while (j-- && j > i)
	{
		if (ft_strchr(set, s1[j]))
			size--;
		else
			break ;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	size = ft_compute_trimmed_size(s1, set);
	strtrim = (char *)malloc(size * sizeof(char));
	if (!strtrim)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	j = 0;
	while (s1[i] != '\0' && --size)
	{
		strtrim[j] = s1[i + j];
		j++;
	}
	strtrim[j] = '\0';
	return (strtrim);
}
