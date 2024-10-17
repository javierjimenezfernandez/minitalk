/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:51:53 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/19 12:38:19 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*aux_dst;
	unsigned const char	*aux_src;

	aux_dst = dst;
	aux_src = src;
	if (!(dst == NULL && src == NULL))
	{
		if (src < dst && dst <= (src + len))
		{
			while (len-- > 0)
				aux_dst[len] = aux_src[len];
		}
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}
