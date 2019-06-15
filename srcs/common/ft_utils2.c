/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:28:15 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 14:59:59 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_min_value(t_list *stack)
{
	int value;

	if (!stack)
		return (0);
	value = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < value)
			value = *(int *)stack->content;
		stack = stack->next;
	}
	return (value);
}

int		ft_get_max_value(t_list *stack)
{
	int value;

	if (!stack)
		return (0);
	value = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > value)
			value = *(int *)stack->content;
		stack = stack->next;
	}
	return (value);
}

int		ft_is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if ((*(int *)stack->content) > (*(int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_execute_instruction(t_instruction *instruction,
								t_list **stack_a, t_list **stack_b)
{
	if (instruction->dest == STACK_A)
		instruction->function(stack_a, stack_b, NO_WRITE);
	else if (instruction->dest == STACK_B)
		instruction->function(stack_b, stack_a, NO_WRITE);
	else
	{
		instruction->function(stack_a, stack_b, NO_WRITE);
		instruction->function(stack_b, stack_a, NO_WRITE);
	}
}
