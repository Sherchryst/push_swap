/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:01:54 by sgah              #+#    #+#             */
/*   Updated: 2021/04/16 14:38:00 by sgah             ###   ########.fr       */
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
***CMD
*/
void		do_cmd(char *cmd, t_stack **a, t_stack **b);

/*
***CMD_TOOLS
*/
void		swap_stack(t_stack **roots);

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
