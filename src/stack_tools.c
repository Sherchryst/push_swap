/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:31:45 by sgah              #+#    #+#             */
/*   Updated: 2021/04/19 16:14:15 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack
	*roots_stack(void)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->i = -1;
	new->next = new;
	new->prev = new;
	return (new);
}

t_stack
	*first_elem(int n, t_stack *roots)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = roots;
	new->prev = roots;
	roots->next = new;
	roots->prev = new;
	return (new);
}

t_stack
	*new_elem_add_back(int n, t_stack *elem)
{
	t_stack	*new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = elem->prev;
	new->next = elem;
	elem->prev->next = new;
	elem->prev = new;
	return (new);
}

t_stack
	*fill_stack(int ac, char **av, int v)
{
	t_stack	*roots;
	t_stack	*first;
	t_stack	*new;
	int		i;

	roots = roots_stack();
	i = ((v == 1) ? 3 : 2) - 1;
	first = first_elem(((v == 1) ? ft_atoi(av[2]) : ft_atoi(av[1])), roots);
	while (++i < ac)
		new = new_elem_add_back(ft_atoi(av[i]), roots);
	return (roots);
}

int
	get_size_stack(t_stack *roots)
{
	t_stack	*tmp;
	int		i;

	tmp = roots->next;
	i = 0;
	while (tmp != roots)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
