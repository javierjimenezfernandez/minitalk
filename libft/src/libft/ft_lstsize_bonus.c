/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:15:32 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/07 17:29:07 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lstsize;
	t_list	*i;

	if (!lst)
		return (0);
	i = lst;
	lstsize = 1;
	while (i->next)
	{
		i = i->next;
		lstsize++;
	}
	return (lstsize);
}
