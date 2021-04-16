/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:22:49 by sgah              #+#    #+#             */
/*   Updated: 2021/04/16 14:54:59 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	swap_stack(t_stack **roots)
{
	t_stack *first;
	t_stack *second;

	if ((*roots)->next == (*roots) || (*roots)->next->next == *roots)
		return ;
	first = (*roots)->next;
	second = (*roots)->next->next;
	printf("%d %d\n", first->n, second->n);
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	(*roots)->next = second;
}
