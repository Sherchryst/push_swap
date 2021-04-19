/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:51:23 by sgah              #+#    #+#             */
/*   Updated: 2021/04/19 16:14:15 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	add_index_stack(t_stack **roots, int *array, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = (*roots)->next;
	while (tmp != (*roots))
	{
		i = -1;
		while (++i < size)
			if (array[i] == tmp->n)
				tmp->i = i;
		tmp = tmp->next;
	}
}

int
	get_markup(t_stack *roots, int type)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = roots->next;
	while (tmp != roots)
	{
		if (tmp->k == type)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int
	add_markup_index(t_stack **roots, int n)
{
	t_stack	*tmp;
	t_stack	*point;
	int		max;

	max = -1;
	tmp = (*roots)->next;
	while (tmp->n != n)
	{
		tmp->k = 0;
		tmp = tmp->next;
	}
	point = NULL;
	while (tmp != (*roots))
	{
		if (point == NULL || (tmp->i > point->i && tmp->i > max))
		{
			tmp->k = 1;
			max = tmp->i;
		}
		else
			tmp->k = 0;
		point = tmp;
		tmp = tmp->next;
	}
	return (get_markup(*roots, 1));
}

int
	add_markup_opti(t_stack **roots)
{
	int		max;
	int		t;
	int		best;
	t_stack *tmp;

	max = -1;
	tmp = (*roots)->next;
	while (tmp != (*roots))
	{
		t = add_markup_index(roots, tmp->n);
		if (t > max)
		{
			max = t;
			best = tmp->n;
		}
		tmp = tmp->next;
	}
	add_markup_index(roots, best);
	return (get_markup(*roots, 1));
}

int
	*lst_mark_to_array(t_stack *roots)
{
	int		*array;
	t_stack	*tmp;
	int		i;
	int		size;

	tmp = roots->next;
	size = get_size_stack(roots);
	array = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (tmp != roots)
	{
		array[i] = tmp->k;
		tmp = tmp->next;
		i++;
	}
	return (array);
}
