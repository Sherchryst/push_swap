/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:15:45 by sgah              #+#    #+#             */
/*   Updated: 2021/04/16 17:24:13 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	swap_stacks(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
}

void
	do_cmd(char *cmd, t_stack **a, t_stack **b)
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
}
