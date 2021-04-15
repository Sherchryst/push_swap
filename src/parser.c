/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:18:05 by sgah              #+#    #+#             */
/*   Updated: 2021/04/15 15:26:03 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int
	ft_isint(int ac, char **av, int v)
{
	long long int	l;
	int				i;
	int				j;

	if (v == 1)
		i = 2;
	else
		i = 1;
	while (i < ac)
	{
		l = ft_atoi(av[i]);
		if (l < -2147483648 || l > 2147483647)
			return (1);
		j = 0;
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int
	check_duplicate(int ac, char **av, int v)
{
	int	i;
	int	j;

	if (v == 1)
		i = 2;
	else
		i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int
	parse(int ac, char **av, int v)
{
	if (ft_isint(ac, av, v))
		return (1);
	if (check_duplicate(ac, av, v))
		return (1);
	return (0);
}
