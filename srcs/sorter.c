/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:04:50 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/08 11:14:51 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			count_lower_nbs(t_list *stack, int value, int size)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (stack && ++i < size)
	{
		count += *((int *)stack->content) < value;
		stack = stack->next;
	}
	return (count);
}

static int			find_median(t_list *stack, int size)
{
	int half;
	int value;
	t_list *list;
	int i;

	if (size % 2 == 0)
		half = (size / 2) -1;
	else
		half = size / 2;
	list = stack;
	i = -1;
	while (list && ++i < size)
	{
		value = *((int *)list->content);
		if (count_lower_nbs(stack, value, size) == half)
			return (value);
		list = list->next;
	}
	ft_printf("CAREFUL ERROR: size -> %d\n", size);
	print_list(stack, 1);
	exit(1);
	return (0);
}

void		sorter(t_list **stack_a, t_list **stack_b, int size)
{
	int median;
	int i;
	int value;
	int top_half_len;

	if (size <= 1)
		return ;
	median = find_median(*stack_a, size);
	i = -1;
	top_half_len = 0;
	while (++i < size)
	{
		value = *((int *)(*stack_a)->content);
		if (value > median)
		{
			push_to_second(stack_b, stack_a);
			top_half_len++;
		}
		rotate_stack(stack_a, NULL);
	}
	ft_printf("MEDIAN: %d\n", median);
	print_lists(*stack_a, *stack_b, NULL);
	i = -1;
	while (++i < size - top_half_len)
		reverse_rotate_stack(stack_a, NULL);
		print_lists(*stack_a, *stack_b, NULL);
	i = -1;
	while (++i < top_half_len)
		push_to_second(stack_a, stack_b);
	print_lists(*stack_a, *stack_b, NULL);
	sorter(stack_a, stack_b, top_half_len);
	i = -1;
	while (++i < top_half_len)
		rotate_stack(stack_a, NULL);
	sorter(stack_a, stack_b, size - top_half_len);
	i = -1;
	while (++i < top_half_len)
		reverse_rotate_stack(stack_a, NULL);
}
