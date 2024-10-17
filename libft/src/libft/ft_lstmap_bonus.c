/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:59:10 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/07 20:44:35 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap_loop(t_list *lst, t_list *new_lst, \
		void *(*f)(void *), void (*del)(void *))
{
	t_list	*i;
	t_list	*new_lst_i;
	void	*new_content;

	i = lst;
	new_lst_i = new_lst;
	while (i->next)
	{
		i = i->next;
		new_content = f(i->content);
		new_lst_i->next = ft_lstnew(new_content);
		if (!new_lst_i->next)
		{
			free(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_lst_i = new_lst_i->next;
	}
	new_lst_i->next = NULL;
	return (new_lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*i;
	t_list	*new_lst;
	void	*new_content;

	if (!lst || !(*f) || !del)
		return (NULL);
	i = lst;
	new_content = f(i->content);
	new_lst = ft_lstnew(new_content);
	if (!new_lst)
	{
		free(new_content);
		ft_lstclear(&new_lst, del);
		return (NULL);
	}
	return (ft_lstmap_loop(lst, new_lst, f, del));
}
