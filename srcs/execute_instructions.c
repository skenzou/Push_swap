/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:34:56 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/08 09:35:45 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two(t_list **stack, t_list **unused)
{
	t_list *second;

	(void)unused;
	if (!*stack || !(*stack)->next)
		return ;
	second = (*stack)->next;
	(*stack)->next = second->next;
	second->next = *stack;
	*stack = second;
}

void	push_to_second(t_list **first, t_list **second)
{
	t_list *tmp;

	if (!*second)
		return ;
	tmp = *second;
	*second = (*second)->next;
	ft_lstadd(first, tmp);
}

void	reverse_rotate_stack(t_list **stack, t_list **unused)
{
	t_list *list;

	(void)unused;
	if (!*stack || !(*stack)->next)
		return ;
	list = *stack;
	while (list->next && list->next->next)
	{
		list = list->next;
	}
	ft_lstadd(stack, list->next);
	list->next = NULL;
}

void	rotate_stack(t_list **stack, t_list **unused)
{
	t_list *tmp;

	(void)unused;
	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstpushback(stack, tmp);
}

void		execute_instructions(t_list **stack_a, t_list **stack_b,
														t_list *instructions)
{
	t_instruction *instruction;

	while (instructions)
	{
		instruction =  (t_instruction *)instructions->content;
		if (instruction->dest == STACK_A)
			instruction->function(stack_a, stack_b);
		else if (instruction->dest == STACK_B)
			instruction->function(stack_b, stack_a);
		else
		{
			instruction->function(stack_a, stack_b);
			instruction->function(stack_b, stack_a);
		}
		instructions = instructions->next;
	}
	if (is_sorted(*stack_a) && !(*stack_b))
		ft_printf(ANSI_GREEN"OK\n"ANSI_RESET);
	else
		ft_printf(ANSI_RED"KO\n"ANSI_RESET);
}
