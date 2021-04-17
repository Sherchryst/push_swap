/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:15:05 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 01:54:36 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	check_is_sorted(t_stack *a)
{
	t_stack	*next;

	next = a->next;
	if (next == a || next->next == a)
		return (1);
	while (next != a && next->next != a)
	{
		if (next->n > next->next->n)
			return (0);
		next = next->next;
	}
	return (1);

}

static void
	checker(t_stack *a, t_stack *b)
{
	if (b->next == b && check_is_sorted(a))
		print_ok();
	else
		print_ko();
}

int
	main(int ac, char **av)
{
	int		v;
	t_stack	*a;
	t_stack	*b;
	char	*cmd;

	v = (ac > 1 && ft_strcmp(av[1], "-v") == 0) ? 1 : 0;
	if ((ac > 2 && v == 1) || (ac > 1 && v == 0))
	{
		if (parse(ac, av, v))
			return (ft_error("Error\n"));
		a = fill_stack(ac, av, v);
		b = roots_stack();
		(v == 1) ? print_game_start(a, b) : 0;
		while (get_next_line(0, &cmd) != 0)
		{
			if (parse_cmd(cmd))
				return (free_all(cmd, a, b) && ft_error("Error\n"));
			do_cmd(cmd, &a, &b, v);
			free(cmd);
		}
		checker(a, b);
		free_all(cmd, a, b);
		v == 1 ? print_game_end() : 0;
	}
	return (0);
}
