/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:15:45 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 13:46:13 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	swap_stacks(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
}

static void
	rotate_stacks(t_stack **a, t_stack **b)
{
	rotate_stack(a);
	rotate_stack(b);
}

static void
	reverse_rotate_stacks(t_stack **a, t_stack **b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}

void
	do_cmd(char *cmd, t_stack **a, t_stack **b, int v)
{
	if (ft_strcmp(cmd, "sa") == 0)
		swap_stack(a);
	else if (ft_strcmp(cmd, "sb") == 0)
		swap_stack(b);
	else if (ft_strcmp(cmd, "ss") == 0)
		swap_stacks(a, b);
	else if (ft_strcmp(cmd, "pa") == 0)
		push_stack(b, a);
	else if (ft_strcmp(cmd, "pb") == 0)
		push_stack(a, b);
	else if (ft_strcmp(cmd, "ra") == 0)
		rotate_stack(a);
	else if (ft_strcmp(cmd, "rb") == 0)
		rotate_stack(b);
	else if (ft_strcmp(cmd, "rr") == 0)
		rotate_stacks(a, b);
	else if (ft_strcmp(cmd, "rra") == 0)
		reverse_rotate_stack(a);
	else if (ft_strcmp(cmd, "rrb") == 0)
		reverse_rotate_stack(b);
	else if (ft_strcmp(cmd, "rrr") == 0)
		reverse_rotate_stacks(a, b);
	v == 1 ? print_game_cmd(cmd, *a, *b) : 0;
}

void
	to_do_cmd(char *cmd, t_stack **a, t_stack **b, int time)
{
	int	i;

	i = -1;
	while (++i < time)
	{
		do_cmd(cmd, a, b, 0);
		printf("%s\n", cmd);
	}
}
