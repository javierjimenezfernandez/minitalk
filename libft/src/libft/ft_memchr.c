/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:23:54 by javjimen          #+#    #+#             */
/*   Updated: 2023/09/28 15:42:32 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*aux_s;

	i = 0;
	aux_s = s;
	while (i + 1 < n)
	{
		if (aux_s[i] == (unsigned char)c)
			return ((void *)&aux_s[i]);
		i++;
	}
	if (aux_s[i] == (unsigned char)c && n != 0)
		return ((void *)&aux_s[i]);
	return (NULL);
}
