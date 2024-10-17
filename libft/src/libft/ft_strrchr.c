/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 10:57:07 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/05 13:17:17 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			ret = ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		ret = ((char *)&s[i]);
	return (ret);
}
