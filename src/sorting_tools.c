/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:16:11 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 15:37:07 by sgah             ###   ########.fr       */
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
