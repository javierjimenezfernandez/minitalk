/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:25:22 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/06 16:13:56 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		num_len;
	int		neg_flag;

	neg_flag = 0;
	num_len = ft_numlen(n);
	num = (char *)ft_calloc((num_len + 1), sizeof (char));
	if (!num)
		return (NULL);
	if (n < 0)
		neg_flag = 1;
	while (num_len--)
	{
		if (neg_flag)
		{
			if (num_len == 0)
				num[num_len] = '-';
			else
				num[num_len] = '0' - (n % 10);
		}
		else
			num[num_len] = '0' + (n % 10);
		n /= 10;
	}
	return (num);
}
