/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:58:51 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/22 01:34:29 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(char const format, va_list ap, int *len)
{
	int		i;
	char	*to_write;

	i = va_arg(ap, int);
	to_write = ft_itoa(i);
	if (!to_write)
	{
		(*len) = -1;
		return (*len);
	}
	ft_printf_putnbr(format, to_write, len);
	free(to_write);
	return (*len);
}
