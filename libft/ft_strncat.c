/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 23:40:33 by sgah              #+#    #+#             */
/*   Updated: 2019/09/09 14:16:36 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	j = ft_strlen(s2);
	i = ft_strlen((const char*)s1);
	if (j < n)
		ft_strcpy(s1 + i, s2);
	else
	{
		ft_strncpy(s1 + i, s2, n);
		s1[i + n] = '\0';
	}
	return (s1);
}
