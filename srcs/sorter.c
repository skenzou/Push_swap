/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:04:50 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/10 12:41:17 by midrissi         ###   ########.fr       */
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
	if (size >= 400)
		half = size / 3;
	list = stack;
	i = -1;
	while (list && ++i < size)
	{
		value = *((int *)list->content);
		if (count_lower_nbs(stack, value, size) == half)
			return (value);
		list = list->next;
	}
	ft_printf("CAREFUL UNEXPECTED ERROR: size -> %d\n", size);
	print_list(stack, 1);
	exit(1);
	return (0);
}

static int		is_size_sorted(t_list *stack, int size)
{
	int i;

	i = -1;
	while (stack && stack->next && ++i < size)
	{
		if ((*(int *)stack->content) > (*(int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int			check_nbs_left(t_list *stack, int size, int median)
{
	int i;
	t_list *save;

	i = -1;
	save = stack;
	while (++i < size)
	{
		if (*((int *)stack->content) <= median)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void launch_sort(int size, t_list **stack_a, t_list **stack_b, char dest)
{
	if (dest == STACK_A)
	{
		if (size <= 3)
			ft_sort_3(stack_a, STACK_A);
		else if (size == 4)
			ft_sort_4(stack_a, stack_b, STACK_A);
		else if (size == 5)
			ft_sort_5(stack_a, stack_b, STACK_A);
	}
	else if (dest == STACK_B)
	{
		if (size <= 3)
			ft_sort_3(stack_b, STACK_B);
		else if (size == 4)
			ft_sort_4(stack_a, stack_b, STACK_B);
		else if (size == 5)
			ft_sort_5(stack_a, stack_b, STACK_B);
	}
}


void		sorter(t_list **stack_a, t_list **stack_b, int size, int initial_size)
{
	int median;
	int i;
	int value;
	int top_half_len;
	int index;

	if (size <= 1)
		return ;
	median = find_median(*stack_a, size);
	i = -1;
	top_half_len = 0;
	if (size == 2)
	{
		ft_sort_2(stack_a, STACK_A);
		return ;
	}
	index = -1;
	while (++index < size)
	{
		value = *((int *)(*stack_a)->content);
		if (value <= median)
		{
			ft_push(stack_b, stack_a, STACK_B);
			top_half_len++;
		}
		else
			ft_rotate(stack_a, NULL, STACK_A);
		if (check_nbs_left(*stack_a, size - index - 1, median))
		{
			index++;
			break ;
		}
	}
	if (top_half_len <= 5)
		launch_sort(top_half_len, stack_a, stack_b, STACK_B);
	if (size != initial_size)
	{
		i = -1;
		while (++i < index - top_half_len)
			ft_reverse_rotate(stack_a, NULL, STACK_A);
	}
	while (*((int *)(*stack_b)->content) < get_last(*stack_b))
		ft_rotate(stack_b, NULL, STACK_B);
	i = -1;
	while (++i < top_half_len)
		ft_push(stack_a, stack_b, STACK_A);
	if (!is_size_sorted(*stack_a, top_half_len))
		sorter(stack_a, stack_b, top_half_len, initial_size);
	i = -1;
	while (++i < top_half_len)
		ft_rotate(stack_a, NULL, STACK_A);
	if (!is_size_sorted(*stack_a, size - top_half_len))
		sorter(stack_a, stack_b, size - top_half_len, initial_size);
	i = -1;
	while (++i < top_half_len)
		ft_reverse_rotate(stack_a, NULL, STACK_A);
}
