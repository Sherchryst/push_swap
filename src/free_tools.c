/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:32:03 by sgah              #+#    #+#             */
/*   Updated: 2021/04/16 13:01:42 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	free_all_stack(t_stack **roots)
{
	t_stack	*to_del;
	t_stack	*next_one;

	to_del = (*roots)->next;
	while (to_del != (*roots))
	{
		next_one = to_del->next;
		free(to_del);
		to_del = next_one;
	}
	free((*roots));
	*roots = NULL;
}

int
	free_all(char *cmd, t_stack *a, t_stack *b)
{
	free(cmd);
	free_all_stack(&a);
	free_all_stack(&b);
	return (1);
}
