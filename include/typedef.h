/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:25:28 by sgah              #+#    #+#             */
/*   Updated: 2021/04/15 13:43:19 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

typedef struct			s_stack
{
	struct s_stack	*prev;
	int				i;
	int				n;
	struct s_stack	*next;
}						t_stack;

#endif
