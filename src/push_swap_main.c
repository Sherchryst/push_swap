/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:11:14 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 20:59:24 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	push_swap(t_stack **a, t_stack **b, int size)
{
	if (size <= 5)
		push_swap_short_sort(a, b, size);
	else
		push_swap_sort(a, b, size);
}

int
	main(int ac, char **av)
{
	int		v;
	t_stack	*a;
	t_stack	*b;
	int		size;

	v = (ac > 1 && ft_strcmp(av[1], "-v") == 0) ? 1 : 0;
	if ((ac > 2 && v == 1) || (ac > 1 && v == 0))
	{
		if (parse(ac, av, v))
			return (ft_error("Error\n"));
		a = fill_stack(ac, av, v);
		b = roots_stack();
		size = (v == 1) ? ac - 2 : ac - 1;
		push_swap(&a, &b, size);
		free_all(NULL, a, b);
	}
	return (0);
}
