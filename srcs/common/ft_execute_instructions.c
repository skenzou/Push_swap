/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:34:56 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 13:43:08 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_swap(t_list **stack_a, t_list **stack_b, char dest)
{
	t_list *second;

	if (dest >= 0)
		ft_write_instructions(&ft_swap, dest);
	if (dest == BOTH)
		ft_swap(stack_b, NULL, NO_WRITE);
	if (!*stack_a || !(*stack_a)->next)
		return ;
	second = (*stack_a)->next;
	(*stack_a)->next = second->next;
	second->next = *stack_a;
	*stack_a = second;
}

void		ft_push(t_list **first, t_list **second, char dest)
{
	t_list *tmp;

	if (dest >= 0)
		ft_write_instructions(&ft_push, dest);
	if (!*second)
		return ;
	tmp = *second;
	*second = (*second)->next;
	ft_lstadd(first, tmp);
}

void		ft_reverse_rotate(t_list **stack_a, t_list **stack_b, char dest)
{
	t_list *list;

	if (dest >= 0)
		ft_write_instructions(&ft_reverse_rotate, dest);
	if (dest == BOTH)
		ft_reverse_rotate(stack_b, NULL, NO_WRITE);
	if (!*stack_a || !(*stack_a)->next)
		return ;
	list = *stack_a;
	while (list->next && list->next->next)
	{
		list = list->next;
	}
	ft_lstadd(stack_a, list->next);
	list->next = NULL;
}

void		ft_rotate(t_list **stack_a, t_list **stack_b, char dest)
{
	t_list *tmp;

	if (dest >= 0)
		ft_write_instructions(&ft_rotate, dest);
	if (dest == BOTH)
		ft_rotate(stack_b, NULL, NO_WRITE);
	if (!*stack_a || !(*stack_a)->next)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstpushback(stack_a, tmp);
}

void		ft_execute_instructions(t_list **stack_a, t_list **stack_b,
								t_list *instructions)
{
	while (instructions)
	{
		ft_execute_instruction((t_instruction *)instructions->content,
															stack_a, stack_b);
		instructions = instructions->next;
	}
	if (ft_is_sorted(*stack_a) && !(*stack_b))
		ft_printf(ANSI_GREEN"OK\n"ANSI_RESET);
	else
		ft_printf(ANSI_RED"KO\n"ANSI_RESET);
}
