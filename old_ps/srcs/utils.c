/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 22:54:12 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/08 07:41:56 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_int_node		create_node(int number, int set, size_t size)
{
	t_int_node node;

	node.set = set;
	node.value = number;
	node.size = size;
	return (node);
}

void			set_node(t_int_node *stack, int new_value)
{
	stack->value = new_value;
	stack->set = SET;
}

void 	print_stack(t_int_node *stack, char name)
{
	int i;
	int size;

	i = -1;
	size = stack[0].size;
	if (name == 'A')
		ft_printf(
		ANSI_BBLUE"========================STACK_A=========================\n");
	else if (name == 'B')
		ft_printf(
		ANSI_BRED"========================STACK_B=========================\n");
	while (++i < size)
		if (stack[i].set)
			ft_printf("stack[%d]: %d\n", i, stack[i].value);
		else
			ft_printf("stack[%d]: Value is not set\n", i);
	ft_printf(
	"========================================================\n"ANSI_RESET);
}

int				init_stack(t_stack *stack_a, t_stack *stack_b, int size)
{
	if (!ac)
		return (1);
	stack_a->size = size;
	stack_b->size = size;
	stack_a->top = -1;
	stack_b->top = -1;
	stack_a->items = (int *)ft_memalloc(sizeof(int) * size);
	stack_b->items = (int *)ft_memalloc(sizeof(int) * size);
	if (!stack_a || ! stack_b)
		return (1);
	return (0);
}
