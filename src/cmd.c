/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:22:49 by sgah              #+#    #+#             */
/*   Updated: 2021/04/16 16:49:30 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	swap_stack(t_stack **roots)
{
	t_stack *first;
	t_stack *second;

	if ((*roots)->next == (*roots) ||
		(*roots)->next->next == *roots)
		return ;
	first = (*roots)->next;
	second = (*roots)->next->next;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	(*roots)->next = second;
}

void
	push_stack(t_stack **src,t_stack **dest)
{
	t_stack	*first_src;

	if ((*src)->next == *src)
		return ;
	first_src = (*src)->next;
	first_src->prev->next = first_src->next;
	first_src->next->prev = first_src->prev;
	first_src->prev = (*dest);
	first_src->next = (*dest)->next;
	(*dest)->next->prev = first_src;
	(*dest)->next = first_src;
}
