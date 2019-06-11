/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 01:49:30 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/11 18:05:32 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <fcntl.h>
# define ANSI_RED		"\x1b[31m"
# define ANSI_GREEN		"\x1b[32m"
# define ANSI_RESET		"\x1b[0m"
# define ANSI_BRED		"\x1b[1m\x1b[31m"
# define ANSI_BBLUE		"\x1b[1m\x1b[34m"
# define ANSI_BCYAN		"\x1b[1m\x1b[36m"
# define NB_INSTRUCTIONS	11
# define NO_WRITE			-1
# define STACK_A			0
# define STACK_B			1
# define BOTH				2
# define VISU				(1 << 0)
# define FROM_FILE			(1 << 1)
# define SLOW				1
# define NORMAL				2

typedef struct	s_instruction
{
	char			*op;
	int				dest;
	void			(*function)(t_list **stack_a, t_list **unused, char dest);
}				t_instruction;

/*
**	PARSE_ARGS.C
*/
int		parse_args(int ac, char **av, t_list **head, char *flags);

/*
**	READ_INSTRUCTIONS.C
*/
int		read_instructions(t_list **head);
void	write_instructions(void			(*function)(t_list **stack_a,
							t_list **unused, char write), char dest);

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
void	ft_swap(t_list **stack, t_list **unused, char write);
void	ft_push(t_list **first, t_list **second, char write);
void	ft_reverse_rotate(t_list **stack, t_list **unused, char write);
void	ft_rotate(t_list **stack, t_list **unused, char write);
void	execute_instructions(t_list **stack_a, t_list **stack_b,
											t_list *instructions);
/*
** SORTER.C
*/
void	sorter(t_list **stack_a, t_list **stack_b, int size, int initial_size);
void	sort_small(t_list **stack, char dest);
/*
** SMALL_SORT.C
*/
void	ft_sort_2(t_list **stack, char dest);
void	ft_sort_3(t_list **stack, char dest);
void	ft_sort_4(t_list **stack_a, t_list **stack_b, char dest);
void	ft_sort_5(t_list **stack_a, t_list **stack_b, char dest);
/*
** SORTER_UTILS.C
*/
int		ft_get_min_index(t_list *stack);
int		ft_get_max_index(t_list *stack);
int		get_last(t_list *list);
int		is_rev_sorted(t_list *stack);
/*
** SORTER_UTILS.C
*/
int		ft_get_max_value(t_list *stack);
int		ft_get_min_value(t_list *stack);

#endif
