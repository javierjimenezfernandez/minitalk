/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:44:56 by javjimen          #+#    #+#             */
/*   Updated: 2023/09/14 14:49:54 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c)
{
	if (65 <= c && c <= 90)
		return (1);
	else
		return (0);
}

static int	ft_islower(int c)
{
	if (97 <= c && c <= 122)
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	else
		return (0);
}
