/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 01:49:30 by midrissi          #+#    #+#             */
/*   Updated: 2019/05/31 23:20:23 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/includes/libft.h"
# define ANSI_RED		"\x1b[31m"
# define ANSI_GREEN		"\x1b[32m"
# define ANSI_RESET		"\x1b[0m"
# define ANSI_BRED		"\x1b[1m\x1b[31m"
# define ANSI_BBLUE		"\x1b[1m\x1b[34m"
# define ANSI_BCYAN		"\x1b[1m\x1b[36m"
# define NB_INSTRUCTIONS	11
# define STACK_A			0
# define STACK_B			1
# define BOTH				2

typedef struct	s_instruction
{
	char			*op;
	int				dest;
	void			(*function)(t_list **stack_a, t_list **unused);
}				t_instruction;

/*
**	PARSE_ARGS.C
*/
int		parse_args(int ac, char **av, t_list **head);

/*
**	READ_INSTRUCTIONS.C
*/
int		read_instructions(t_list **head);

/*
**	UTILS.C
*/
int		add_to_list(t_list **head, void *data, size_t size);
void	print_list(t_list *list, char number);
void	print_lists(t_list *stack_a, t_list *stack_b, t_list *instructions);
void	destroy_lists(t_list *stack_a, t_list *stack_b, t_list *instructions);
int		is_sorted(t_list *stack);

/*
**	EXECUTE_INSTRUCTIONS.C
*/
void	swap_two(t_list **stack, t_list **unused);
void	push_to_second(t_list **first, t_list **second);
void	reverse_rotate_stack(t_list **stack, t_list **unused);
void	rotate_stack(t_list **stack, t_list **unused);
void	execute_instructions(t_list **stack_a, t_list **stack_b,
														t_list *instructions);

#endif
