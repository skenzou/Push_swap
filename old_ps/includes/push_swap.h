/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 23:26:42 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/08 08:21:39 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../libft/includes/libft.h"
# define ANSI_RED		"\x1b[31m"
# define ANSI_GREEN		"\x1b[32m"
# define ANSI_RESET		"\x1b[0m"
# define ANSI_BRED		"\x1b[1m\x1b[31m"
# define ANSI_BBLUE		"\x1b[1m\x1b[34m"
# define ANSI_BCYAN		"\x1b[1m\x1b[36m"
# define SET 1
# define UNSET 0

typedef struct s_stack
{
	size_t		size;
	size_t		top;
	int			*items;
}				t_stack;
/*
** UTILS.C
*/
t_int_node		create_node(int number, int set, size_t size);
t_int_node		*init_stack(int size);
void			print_stack(t_int_node *stack, char name);
void			set_node(t_int_node *stack, int new_value);
/*
** PARSE_ARGS.C
*/
t_int_node		*parse_args(int ac, char **av);
/*
** SORTER.C
*/
void		sorter(t_int_node *stack_a, t_int_node *stack_b);

#endif
