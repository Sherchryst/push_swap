/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:22:49 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 02:31:28 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	swap_stack(t_stack **roots)
{
	t_stack *second;

	if ((*roots)->next == (*roots) ||
		(*roots)->next->next == *roots)
		return ;
	second = release((*roots)->next->next);
	add_after(*roots, second);
}

void
	push_stack(t_stack **src, t_stack **dest)
{
	t_stack	*first_src;

	if ((*src)->next == *src)
		return ;
	first_src = release((*src)->next);
	add_after(*dest, first_src);
}

void
	rotate_stack(t_stack **roots)
{
	t_stack	*first;

	if ((*roots)->next == *roots &&
		(*roots)->next->next == *roots)
		return ;
	first = release((*roots)->next);
	add_before(*roots, first);
}

void
	reverse_rotate_stack(t_stack **roots)
{
	t_stack	*last;

	if ((*roots)->next == *roots &&
		(*roots)->next->next == *roots)
		return ;
	last = release((*roots)->prev);
	add_after(*roots, last);
}
