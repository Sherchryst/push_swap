/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:28:45 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 21:02:02 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*MAYBE apply n_cmd
*/
int
	need_to_swap(t_stack **a, t_stack **b)
{
	int	*array;
	int	mark1;
	int	mark2;
	int	ret;

	mark1 = get_markup(*a, 1);
	array = lst_mark_to_array(*a);
	do_cmd("sa", a, b, 0);
	mark2 = add_markup_opti(a);
	ret = (mark2 > mark1) ? 1 : 0;
	do_cmd("sa", a, b, 0);
	fill_mark(a, array);
	free(array);
	return (ret);
}

void
	push_swap_sort(t_stack **a, t_stack **b, int size)
{
	int		*array;

	array = lst_to_array(*a, size);
	quicksort(array, 0, size - 1);
	add_index_stack(a, array, size);
	add_markup_opti(a);
	while (get_markup(*a, 0) != 0)
	{
		if(need_to_swap(a, b) == 1)
		{
			to_do_cmd("sa", a, b, 1);
			add_markup_opti(a);
		}
		else if ((*a)->next->k == 0)
			to_do_cmd("pb", a, b, 1);
		else
			to_do_cmd("ra", a, b, 1);
	}
	while ( (*b)->next != (*b))
		pushback_one(a, b, nb_pushback_opti(*a, *b));
	align("ra", "rra", a, b);
	free(array);
}
