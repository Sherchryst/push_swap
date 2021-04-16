/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:18:05 by sgah              #+#    #+#             */
/*   Updated: 2021/04/16 14:00:19 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int
	parse(int ac, char **av, int v)
{
	long long int	l;
	int				i;
	int				j;
	int				k;

	i = ((v == 1) ? 2 : 1) - 1;
	while (++i < ac)
	{
		l = ft_atoi(av[i]);
		if (l < -2147483648 || l > 2147483647)
			return (1);
		j = -1;
		while (av[i][++j] != '\0')
			if (ft_isdigit(av[i][j]) == 0 &&
				(j == 0) ? (av[i][j] != '-') : (av[i][j] == '-'))
				return (1);
		k = i;
		while (++k < ac)
			if (ft_atoi(av[i]) == ft_atoi(av[k]))
				return (1);
	}
	return (0);
}

int
	parse_cmd(char *cmd)
{
	if (ft_strncmp(cmd, "s", 1) == 0)
	{
		if (ft_strcmp(cmd, "sa") == 0 || ft_strcmp(cmd, "sb") == 0 ||
			ft_strcmp(cmd, "ss") == 0)
			return (0);
	}
	else if (ft_strncmp(cmd, "p", 1) == 0)
	{
		if (ft_strcmp(cmd, "pa") == 0 || ft_strcmp(cmd, "pb") == 0)
			return (0);
	}
	else if (ft_strncmp(cmd, "r", 1) == 0)
	{
		if (ft_strcmp(cmd, "ra") == 0 || ft_strcmp(cmd, "rb") == 0 ||
			ft_strcmp(cmd, "rr") == 0 || ft_strcmp(cmd, "rra") == 0 ||
			ft_strcmp(cmd, "rrb") == 0 || ft_strcmp(cmd, "rrr") == 0)
			return (0);
	}
	return (1);
}
