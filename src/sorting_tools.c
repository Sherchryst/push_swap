/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:16:11 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 20:18:11 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	get_max_n(t_stack *roots)
{
	t_stack	*tmp;
	int		n;

	tmp = roots->next;
	n = tmp->n;
	while (tmp != roots)
	{
		if (tmp->n > n)
			n = tmp->n;
		tmp = tmp->next;
	}
	return (n);
}

int
	get_min_n(t_stack *roots)
{
	t_stack	*tmp;
	int		n;

	tmp = roots->next;
	n = tmp->n;
	while (tmp != roots)
	{
		if (tmp->n < n)
			n = tmp->n;
		tmp = tmp->next;
	}
	return (n);
}

t_stack
	*get_last_elem(t_stack *roots)
{
	t_stack	*tmp;

	tmp = roots->prev;
	return (tmp);
}

int
	*lst_to_array(t_stack *roots, int size)
{
	int		*array;
	t_stack	*tmp;
	int		i;

	tmp = roots->next;
	array = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (tmp != roots)
	{
		array[i] = tmp->n;
		tmp = tmp->next;
		i++;
	}
	return (array);
}

void
	fill_mark(t_stack **roots, int *array)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = (*roots)->next;
	while (tmp != *roots)
	{
		tmp->k = array[i];
		tmp = tmp->next;
		i++;
	}
}
