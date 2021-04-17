/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_lst_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:38:00 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 02:27:51 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack
	*release(t_stack *elem)
{
	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;
	return (elem);
}

void
	add_before(t_stack *this, t_stack *to_add)
{
	to_add->prev = this->prev;
	to_add->next = this;
	this->prev->next = to_add;
	this->prev = to_add;
}

void
	add_after(t_stack *this, t_stack *to_add)
{
	to_add->prev = this;
	to_add->next = this->next;
	this->next->prev = to_add;
	this->next = to_add;
}
