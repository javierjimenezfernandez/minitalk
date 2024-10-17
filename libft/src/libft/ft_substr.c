/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:29:44 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/19 12:40:01 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	size;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		size = 1;
	else if (len > (s_len - start))
		size = s_len - start + 1;
	else
		size = len + 1;
	substr = (char *)malloc(size * sizeof(char));
	if (!substr)
		return (NULL);
	if (start > s_len)
		ft_strlcpy(substr, s, size);
	else
		ft_strlcpy(substr, s + start, size);
	return (substr);
}
