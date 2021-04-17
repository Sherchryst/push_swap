/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 18:35:47 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 18:38:53 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	swap(int *a, int i, int j)
{
	int temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void
	quicksort(int *a, int first, int last)
{
	int i;
	int j;
	int	pivot;
	int temp;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (a[i] <= a[pivot] && i < last)
				i++;
			while (a[j] > a[pivot])
				j--;
			if (i < j)
				swap(a, i, j);
		}
		temp = a[pivot];
		a[pivot] = a[j];
		a[j] = temp;
		quicksort(a, first, j - 1);
		quicksort(a, j + 1, last);
	}
}
