/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:15:05 by sgah              #+#    #+#             */
/*   Updated: 2021/04/16 11:48:26 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	main(int ac, char **av)
{
	int		v;
	t_stack	*a;
	t_stack	*b;
	char	*cmd;

	if (ac > 1)
		v = (ft_strcmp(av[1], "-v") == 0) ? 1 : 0;
	if ((ac > 2 && v == 1) || (ac > 1 && v == 0))
	{
		if (parse(ac, av, v))
			return (ft_error("Error\n"));
		a = fill_stack(ac, av, v);
		b = NULL;
		while (get_next_line(0, &cmd) != 0)
		{
			if (parse_cmd(cmd))
				return (free_all(cmd, a) && ft_error("Error\n"));
			free(cmd);
		}
		free_all(cmd, a);
	}
	return (0);
}
