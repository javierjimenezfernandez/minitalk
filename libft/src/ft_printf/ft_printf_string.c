/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:56:58 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/22 01:34:48 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_string(va_list ap, int *len)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
	{
		if (write(1, "(null)", 6) == -1)
		{
			(*len) = -1;
			return (*len);
		}
		(*len) += 6;
		return (*len);
	}
	while (*s)
	{
		if (write(1, s, 1) == -1)
		{
			(*len) = -1;
			return (*len);
		}
		(*len)++;
		s++;
	}
	return (*len);
}
