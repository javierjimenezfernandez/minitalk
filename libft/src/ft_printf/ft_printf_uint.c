/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:59:35 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/22 01:34:53 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_uint(char const format, va_list ap, int *len)
{
	unsigned int	u;
	char			*to_write;

	u = va_arg(ap, unsigned int);
	to_write = ft_utoa_base(u, ft_baselen(format));
	if (!to_write)
	{
		(*len) = -1;
		return (*len);
	}
	ft_printf_putnbr(format, to_write, len);
	free(to_write);
	return (*len);
}
