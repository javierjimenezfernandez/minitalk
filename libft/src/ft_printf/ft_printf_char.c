/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:55:37 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/22 01:34:08 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list ap, int *len)
{
	char	c;

	c = va_arg(ap, int);
	if (write(1, &c, 1) == -1)
		(*len) = -1;
	else
		(*len)++;
	return (*len);
}