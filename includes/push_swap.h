/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 01:49:30 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 15:55:32 by midrissi         ###   ########.fr       */
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

typedef struct	s_instruction
{
	char			*op;
	int				dest;
	void			(*function)(t_list **stack_a, t_list **unused, char dest);
}				t_instruction;

/*
** ***************************COMMON***************************
*/
/*
** FT_ARG_CHECKER.C
*/
int				ft_arg_checker(t_list **head, char *input, int *count);
/*
**	FT_EXECUTE_INSTRUCTIONS.C
*/
void			ft_swap(t_list **stack, t_list **unused, char write);
void			ft_push(t_list **first, t_list **second, char write);
void			ft_reverse_rotate(t_list **stack, t_list **unused, char write);
void			ft_rotate(t_list **stack, t_list **unused, char write);
void			ft_execute_instructions(t_list **stack_a, t_list **stack_b,
														t_list *instructions);
/*
**	FT_PARSE_ARGS.C
*/
int				ft_parse_args(int ac, char **av, t_list **head, char *flags);
/*
** FT_READ_FROM_FILE.C
*/
int				ft_read_from_file(char *file, t_list **head);
/*
**	READ_INSTRUCTIONS.C
*/
int				ft_read_instructions(t_list **head, char *file);
void			ft_write_instructions(void (*function)(t_list **stack_a,
									t_list **unused, char write), char dest);
/*
**	FT_UTILS.C
*/
int				ft_add_to_list(t_list **head, void *data, size_t size);
int				ft_is_not_in_list(int number, t_list *list);
void			ft_print_lists(t_list *stack_a, t_list *stack_b,
														t_list *instructions);
void			ft_destroy_lists(t_list *stack_a, t_list *stack_b,
														t_list *instruction);

/*
** FT_UTILS2.C
*/
int				ft_get_min_value(t_list *stack);
int				ft_get_max_value(t_list *stack);
int				ft_is_sorted(t_list *stack);
void			ft_execute_instruction(t_instruction *instruction,
											t_list **stack_a, t_list **stack_b);
/*
** ************************************************************
*/

/*
** **************************PUSH_SWAP*************************
*/
/*
** FT_SORT_2.C
*/
void			ft_sort_2(t_list **stack, char dest);
/*
** FT_SORT_3.C
*/
void			ft_sort_3(t_list **stack, char dest);
/*
** FT_SORT_4.C
*/
void			ft_sort_4(t_list **stack_a, t_list **stack_b, char dest);
/*
** FT_SORT_5.C
*/
void			ft_sort_5(t_list **stack_a, t_list **stack_b, char dest);
/*
** FT_SORT.C
*/
void			ft_sort(t_list **stack_a, t_list **stack_b, int size,
												int initial_size, int first);
void			sort_small(t_list **stack, char dest);
void			ft_launch_sort(int size, t_list **stack_a, t_list **stack_b);
/*
** FT_UTILS.C
*/
int				ft_get_min_index(t_list *stack);
int				ft_get_max_index(t_list *stack);
int				ft_get_last(t_list *list);
int				ft_is_rev_sorted(t_list *stack);
void			ft_sort_tab(int *tab, int size);
/*
** ************************************************************
*/

#endif
