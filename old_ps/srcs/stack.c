/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 07:43:19 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/08 08:21:52 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_top(t_stack *stack)
{
	int		tmp;

	tmp = stack->items[stack->top];
	stack->items[stack->top - 1] = tmp;
}

void 		pop(t_stack *stack)
{
	stack->top--;
}

void		push(t_stack *stack, int value)
{
	stack->items[++stack->top] = value;
}

void		push_to_second(t_stack *first, t_stack *second)
{
	push(second, first[first->top]);
	pop(first);
}
