/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:01:54 by sgah              #+#    #+#             */
/*   Updated: 2021/04/16 18:02:54 by sgah             ###   ########.fr       */
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
***CMD_TOOLS
*/
void		do_cmd(char *cmd, t_stack **a, t_stack **b);

/*
***CMD
*/
void		swap_stack(t_stack **roots);
void		push_stack(t_stack **src,t_stack **dest);
void		rotate_stack(t_stack **roots);

/*
***CMD_LST_TOOLS
*/
t_stack		*release(t_stack *elem);
void		add_after(t_stack *this, t_stack *to_add);
void		add_before(t_stack *this, t_stack *to_add);

/*
***PARSER
*/
int			parse(int ac, char **a, int v);
int			parse_cmd(char *cmd);

/*
***STACK_TOOLS
*/
t_stack		*fill_stack(int ac, char **av, int v);
t_stack		*roots_stack(void);

/*
***PRINT_GAMES
*/
void		print_game_start(t_stack *a, t_stack *b);
void		print_game_cmd(char *cmd, t_stack *a, t_stack *b);

/*
***PRINT_STACKS
*/
void		print_stacks(t_stack *a, t_stack *b);

/*
***FREE_TOOLS
*/
int			free_all(char *cmd, t_stack *a, t_stack *b);

#endif
