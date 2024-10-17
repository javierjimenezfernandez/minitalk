/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:18:35 by javjimen          #+#    #+#             */
/*   Updated: 2023/09/15 17:02:18 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int					i;
	unsigned char		*aux_dst;
	const unsigned char	*aux_src;

	i = 0;
	aux_dst = dst;
	aux_src = src;
	if (!(dst == NULL && src == NULL))
	{
		while (n > 0)
		{
			aux_dst[i] = aux_src[i];
			i++;
			n--;
		}
	}
	return (dst);
}
