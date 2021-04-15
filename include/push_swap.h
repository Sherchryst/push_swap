/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:01:54 by sgah              #+#    #+#             */
/*   Updated: 2021/04/15 15:42:46 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "typedef.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

/*
***PARSER
*/
int			parse(int ac, char **a, int v);

/*
***STACK_TOOLS
*/
t_stack		*fill_stack(int ac, char **av, int v);

/*
***PRINT_TITLES
*/
void		print_game_start(t_stack *a, t_stack *b);

/*
***PRINT_STACKS
*/
void		print_stacks(t_stack *a, t_stack *b);

/*
***FREE_TOOLS
*/
void		free_all(t_stack *a);

#endif
