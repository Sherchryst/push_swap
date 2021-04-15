/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:18:26 by sgah              #+#    #+#             */
/*   Updated: 2021/04/14 11:48:49 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *str)
{
	long long unsigned int	i;
	long long unsigned int	r;
	int						s;
	long long unsigned int	t;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		t = str[i] - '0';
		r = r * 10 + t;
		i++;
	}
	if (r > 9223372036854775807)
		return (s == 1 ? -1 : 0);
	return (r * s);
}
