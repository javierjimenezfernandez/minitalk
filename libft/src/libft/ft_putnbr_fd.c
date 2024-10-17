/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:57:54 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/06 18:08:04 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*base;
	int		base_len;
	int		q;
	int		m;

	if (fd < 0)
		return ;
	base = "0123456789";
	base_len = 10;
	q = n / base_len;
	m = n % base_len;
	if (q != 0)
		ft_putnbr_fd(q, fd);
	else if (m < 0)
		ft_putchar_fd('-', fd);
	if (m < 0)
		ft_putchar_fd(base[-m], fd);
	else
		ft_putchar_fd(base[m], fd);
}
