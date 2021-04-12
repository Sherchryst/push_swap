/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:16:58 by sgah              #+#    #+#             */
/*   Updated: 2019/09/09 20:04:37 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t n;

	i = 0;
	while (haystack[i])
	{
		n = 0;
		while (haystack[i] == needle[n] && needle[n])
		{
			i++;
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)haystack + i - n);
		else
			i = i - n;
		i++;
	}
	if (haystack[i] == needle[n])
		return ((char*)haystack + n);
	return (NULL);
}
