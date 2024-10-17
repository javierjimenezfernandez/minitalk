/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:23:33 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/06 17:08:30 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_f;
	char			aux[2];

	if (!s || !f)
		return (NULL);
	i = 0;
	aux[1] = '\0';
	s_f = (char *)ft_calloc((ft_strlen(s) + 1), sizeof (char));
	if (!s_f)
		return (NULL);
	while (s[i])
	{
		aux[0] = f(i, s[i]);
		ft_strlcat(s_f, aux, ft_strlen(s_f) + 2);
		i++;
	}
	return (s_f);
}
