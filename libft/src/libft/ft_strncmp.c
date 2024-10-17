/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 11:07:32 by javjimen          #+#    #+#             */
/*   Updated: 2023/09/28 15:40:43 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		cmp;

	i = 0;
	cmp = 0;
	while (s1[i] != '\0' && i + 1 < n)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (n != 0)
		cmp = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (cmp);
}
