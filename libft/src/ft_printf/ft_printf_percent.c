/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:00:36 by javjimen          #+#    #+#             */
/*   Updated: 2024/02/22 01:34:35 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_percent(char const format, int *len)
{
	if (write(1, &format, 1) == -1)
		(*len) = -1;
	else
		(*len)++;
	return (*len);
}
