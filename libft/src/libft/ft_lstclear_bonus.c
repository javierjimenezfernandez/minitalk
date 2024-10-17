/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:20:02 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/07 20:04:33 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*to_clear;

	if (!lst || !(*lst) || !del)
		return ;
	i = *lst;
	while (i->next)
	{
		to_clear = i;
		i = i->next;
		ft_lstdelone(to_clear, del);
	}
	ft_lstdelone(i, del);
	*lst = NULL;
}
