/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:51:49 by javjimen          #+#    #+#             */
/*   Updated: 2023/09/28 12:02:55 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	int					cmp;
	unsigned const char	*aux_s1;
	unsigned const char	*aux_s2;

	i = 0;
	cmp = 0;
	aux_s1 = s1;
	aux_s2 = s2;
	while (i + 1 < n)
	{
		if (aux_s1[i] != aux_s2[i])
			break ;
		i++;
	}
	if (n != 0)
		cmp = (unsigned char)aux_s1[i] - (unsigned char)aux_s2[i];
	return (cmp);
}
