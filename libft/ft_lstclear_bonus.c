/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:20:13 by sgah              #+#    #+#             */
/*   Updated: 2019/10/09 13:20:33 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **alst, void (*del)(void*))
{
	t_list	*to_del;
	t_list	*next_one;

	to_del = *alst;
	while (to_del)
	{
		next_one = to_del->next;
		del(to_del->content);
		free(to_del);
		to_del = next_one;
	}
	*alst = NULL;
}
