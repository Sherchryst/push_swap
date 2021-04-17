/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:01:54 by sgah              #+#    #+#             */
/*   Updated: 2021/04/17 20:59:09 by sgah             ###   ########.fr       */
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
void		do_cmd(char *cmd, t_stack **a, t_stack **b, int v);
void		to_do_cmd(char *cmd, t_stack **a, t_stack **b, int time);

/*
***CMD
*/
void		swap_stack(t_stack **roots);
void		push_stack(t_stack **src, t_stack **dest);
void		rotate_stack(t_stack **roots);
void		reverse_rotate_stack(t_stack **roots);

/*
***CMD_LST_TOOLS
*/
t_stack		*release(t_stack *elem);
void		add_after(t_stack *this, t_stack *to_add);
void		add_before(t_stack *this, t_stack *to_add);
int			get_index(t_stack *roots, int n);

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
int			get_size_stack(t_stack *roots);

/*
***PRINT_GAMES
*/
void		print_game_start(t_stack *a, t_stack *b);
void		print_game_cmd(char *cmd, t_stack *a, t_stack *b);
void		print_game_end(void);
void		print_ok(void);
void		print_ko(void);

/*
***PRINT_STACKS
*/
void		print_stacks(t_stack *a, t_stack *b);

/*
***SORTING
*/
void		push_swap_short_sort(t_stack **a, t_stack **b, int size);
void		push_swap_sort(t_stack **a, t_stack **b, int size);

/*
***SORTING_TOOLS
*/
int			get_max_n(t_stack *roots);
int			get_min_n(t_stack *roots);
t_stack		*get_last_elem(t_stack *roots);
int			*lst_to_array(t_stack *roost, int size);
void		add_index_stack(t_stack **roots, int *array, int size);
int			get_markup(t_stack *roots, int type);
int			add_markup_index(t_stack **roots, int n);
int			add_markup_opti(t_stack **roots);
int			*lst_mark_to_array(t_stack *roots);
void		fill_mark(t_stack **roots, int *array);
void		align(char *c1, char *c2, t_stack **s1, t_stack **s2);
void		pushback_one(t_stack **a, t_stack **b, int n);
int			get_index_next(t_stack *s, int n);
int			nb_pushback_opti(t_stack *a, t_stack *b);

/*
***QUICKSORT
*/
void		quicksort(int *a, int first, int last);

/*
***FREE_TOOLS
*/
int			free_all(char *cmd, t_stack *a, t_stack *b);

/*
***TOOLS
*/
int			ft_min(int a, int b);
int			ft_max(int a, int b);

#endif
