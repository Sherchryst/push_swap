/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:28:05 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 20:45:32 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	get_index_next(t_stack *s, int n)
{
	int i;
	int index;
	int min;
	int max;
	int *arr;

	min = get_min_n(s);
	max = get_max_n(s);
	arr = lst_to_array(s, get_size_stack(s));
	quicksort(arr, 0, get_size_stack(s) - 1);
	if (n < min || n > max)
		index = get_index(s, min);
	else
	{
		i = 0;
		while (n > arr[i])
			i++;
		index = get_index(s, arr[i]);
	}
	free(arr);
	return (index);
}

static void
	pushback_case1(t_stack **a, t_stack **b, int i, int j)
{
	to_do_cmd("rr", a, b, ft_min(i, j));
	to_do_cmd("ra", a, b, ft_max(0, i - ft_min(i, j)));
	to_do_cmd("rb", a, b, ft_max(0, j - ft_min(i, j)));
}

static void
	pushback_case2(t_stack **a, t_stack **b, int i, int j)
{
	int s2;

	s2 = get_size_stack(*b);
	to_do_cmd("ra", a, b, i);
	to_do_cmd("rrb", a, b, s2 - j);
}

void
	pushback_one(t_stack **a, t_stack **b, int n)
{
	int	i;
	int	j;
	int	s1;
	int	s2;

	i = get_index_next(*a, n);
	j = get_index(*b, n);
	s1 = get_size_stack(*a);
	s2 = get_size_stack(*b);
	if (i < s1 / 2 + 1 && j < s2 / 2 + 1)
		pushback_case1(a, b, i, j);
	else if (i < s1 / 2 + 1 && j >= s2 / 2 + 1)
		pushback_case2(a, b, i, j);
	else if (i >= s1 / 2 + 1 && j < s2 / 2 + 1)
	{
		to_do_cmd("rra", a, b, s1 - i);
		to_do_cmd("rb", a, b, j);
	}
	else if (i >= s1 / 2 + 1 && j >= s2 / 2 + 1)
	{
		to_do_cmd("rrr", a, b, ft_min(s1 - i, s2 - j));
		to_do_cmd("rra", a, b, ft_max(0, s1 - i - ft_min(s1 - i, s2 - j)));
		to_do_cmd("rrb", a, b, ft_max(0, s2 - j - ft_min(s1 - i, s2 - j)));
	}
	to_do_cmd("pa", a, b, 1);
}

void
	align(char *c1, char *c2, t_stack **s1, t_stack **s2)
{
	int min;
	int i;
	int size;

	min = get_min_n(*s1);
	i = get_index(*s1, min);
	size = get_size_stack(*s1);
	if (i < size / 2 + 1)
		to_do_cmd(c1, s1, s2, i);
	else
		to_do_cmd(c2, s1, s2, size - i);
}
