/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:43:58 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/05 13:07:28 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s1_copy;

	size = ft_strlen(s1) + 1;
	s1_copy = (char *)malloc(size * sizeof(char));
	if (s1_copy)
		ft_strlcpy(s1_copy, s1, size);
	return (s1_copy);
}
