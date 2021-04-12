/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:25:23 by sgah              #+#    #+#             */
/*   Updated: 2021/03/07 05:39:51 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_elemdel(void *content)
{
	free(content);
	content = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(void *))
{
	t_list *first;
	t_list *the_one;

	if (!(first = ft_lstnew(lst->content)))
		return (NULL);
	first = f(lst->content);
	the_one = first;
	lst = lst->next;
	while (lst)
	{
		if (!(the_one->next = ft_lstnew(lst->content)))
		{
			ft_lstclear(&first, &ft_elemdel);
			return (NULL);
		}
		the_one->next = f((the_one->next)->content);
		the_one = the_one->next;
		lst = lst->next;
	}
	return (first);
}
