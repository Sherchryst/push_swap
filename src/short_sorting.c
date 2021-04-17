/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:47:19 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 16:09:06 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	push_swap_sort_4_5_loop(t_stack **a, t_stack **b)
{
	if ((*b)->next->n < get_min_n(*a) || (*b)->next->n > get_max_n(*a))
		while ((*a)->next->n != get_min_n(*a))
			to_do_cmd("ra", a, b, 1);
	if ((*b)->next->n < get_min_n(*a))
		to_do_cmd("pa", a, b, 1);
	else if ((*b)->next->n > get_max_n(*a))
	{
		to_do_cmd("pa", a, b, 1);
		to_do_cmd("ra", a, b, 1);
	}
	else
	{
		while (!((*b)->next->n < (*a)->next->n &&
				(*b)->next->n > get_last_elem(*a)->n))
			to_do_cmd("ra", a, b, 1);
		to_do_cmd("pa", a, b, 1);
	}
}

void
	push_swap_sort_4_5(t_stack **a, t_stack **b, int size)
{
	while (size - 3 > 0)
	{
		push_swap_sort_4_5_loop(a, b);
		size--;
	}
	while ((*a)->next->n != get_min_n(*a))
		to_do_cmd("ra", a, b, 1);
}

void
	push_swap_sort_3(t_stack **a, t_stack **b)
{
	(*a)->next = (*a)->next;
	if ((*a)->next->n < (*a)->next->next->n && (*a)->next->n < (*a)->next\
		->next->next->n && (*a)->next->next->n > (*a)->next->next->next->n)
	{
		to_do_cmd("sa", a, b, 1);
		to_do_cmd("ra", a, b, 1);
	}
	if ((*a)->next->n > (*a)->next->next->n && (*a)->next->n < (*a)->next\
		->next->next->n && (*a)->next->next->n < (*a)->next->next->next->n)
		to_do_cmd("sa", a, b, 1);
	if ((*a)->next->n < (*a)->next->next->n && (*a)->next->n > (*a)->next\
		->next->next->n && (*a)->next->next->n > (*a)->next->next->next->n)
		to_do_cmd("rra", a, b, 1);
	if ((*a)->next->n > (*a)->next->next->n && (*a)->next->n > (*a)->next\
		->next->next->n && (*a)->next->next->n < (*a)->next->next->next->n)
		to_do_cmd("ra", a, b, 1);
	if ((*a)->next->n > (*a)->next->next->n && (*a)->next->n > (*a)->next\
		->next->next->n && (*a)->next->next->n > (*a)->next->next->next->n)
	{
		to_do_cmd("sa", a, b, 1);
		to_do_cmd("rra", a, b, 1);
	}
}

void
	push_swap_short_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if ((*a)->next->n == get_max_n(*a))
			to_do_cmd("sa", a, b, 1);
	}
	else if (size == 3)
		push_swap_sort_3(a, b);
	else if (size == 4 || size == 5)
	{
		to_do_cmd("pb", a, b, size - 3);
		push_swap_sort_3(a, b);
		if (size == 5 && (*b)->next->n > (*b)->next->next->n)
			to_do_cmd("sb", a, b, 1);
		push_swap_sort_4_5(a, b, size);
	}
}
