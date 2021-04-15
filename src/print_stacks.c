/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:04:23 by sgah              #+#    #+#             */
/*   Updated: 2021/04/15 15:23:20 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	print_stacks(t_stack *a, t_stack *b)
{
	t_stack	*atmp;
	t_stack	*btmp;

	atmp = a->next;
	btmp = (b != NULL) ? b->next : NULL;
	while (atmp != a || (btmp != NULL && btmp != b))
	{
		if (atmp != a)
		{
			printf("%11d\t", atmp->n);
			atmp = atmp->next;
		}
		else
			printf("           \t");
		if (btmp != NULL && btmp != b)
		{
			printf("%11d\n", btmp->n);
			btmp = btmp->next;
		}
		else
			printf("\n");
	}
	printf("-----------\t-----------\n");
	printf("          a\t");
	printf("          b\n");
}
