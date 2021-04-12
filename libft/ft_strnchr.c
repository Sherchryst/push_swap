/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:11:10 by sgah              #+#    #+#             */
/*   Updated: 2019/08/22 16:16:22 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, size_t len)
{
	unsigned char	ch;
	size_t			i;

	i = 0;
	ch = c;
	while (s[i] && i < len)
	{
		if (((unsigned char *)s)[i] == ch)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
