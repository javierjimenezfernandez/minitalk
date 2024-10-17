/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:05:18 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/19 15:57:44 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_isfound(const char *candidate, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0' && len > 0)
	{
		if (candidate[i] != needle[i])
			return (NULL);
		i++;
		len--;
	}
	if (needle[i] != '\0')
		return (NULL);
	else
		return ((char *)candidate);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ndl_len;
	char	*found;

	if ((!haystack || !needle) && len == 0)
		return (NULL);
	i = 0;
	ndl_len = ft_strlen(needle);
	if (ndl_len == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > 0)
	{
		if (haystack[i] == needle[0])
		{
			found = ft_isfound(&haystack[i], needle, len);
			if (found)
				return (found);
		}
		i++;
		len--;
	}
	return (NULL);
}
