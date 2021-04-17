/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 20:48:18 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 20:58:35 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	nb_pushback_one(t_stack *a, t_stack *b, int n)
{
	int	i;
	int	j;
	int	s1;
	int	s2;

	i = get_index_next(a, n);
	j = get_index(b, n);
	s1 = get_size_stack(a);
	s2 = get_size_stack(b);
	if (i < s1 / 2 + 1 && j < s2 / 2 + 1)
		return (ft_max(i, j));
	else if (i < s1 / 2 + 1 && j >= s2 / 2 + 1)
		return (i + s2 - j);
	else if (i >= s1 / 2 + 1 && j < s2 / 2 + 1)
		return (s1 - i + j);
	else if (i >= s1 / 2 + 1 && j >= s2 / 2 + 1)
		return (ft_max(s1 - i, s2 - j));
	else
		return (-1);
}

int
	nb_pushback_opti(t_stack *a, t_stack *b)
{
	int		min;
	int		best;
	int		n;
	t_stack	*tmp;

	tmp = b->next;
	min = nb_pushback_one(a, b, tmp->n);
	best = tmp->n;
	while (tmp != b)
	{
		n = nb_pushback_one(a, b, tmp->n);
		if (n < min)
		{
			min = n;
			best = tmp->n;
		}
		tmp = tmp->next;
	}
	return (best);
}
