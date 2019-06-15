/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:38:55 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 17:50:46 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_post_rotate(t_list **stack_a, t_list **stack_b, int *size,
																	int count)
{
	int min;

	(*size)--;
	ft_push(stack_a, stack_b, STACK_A);
	min = ft_get_min_index(*stack_b);
	if (*stack_b && min < *size / 2)
		ft_rotate(stack_a, stack_b, BOTH);
	else
		ft_rotate(stack_a, NULL, STACK_A);
	while (count--)
	{
		ft_rotate(stack_a, NULL, STACK_A);
		(*size)--;
	}
}

static void		ft_exec_rrbs(t_list **stack_a, t_list **stack_b, int *size,
																		int pos)
{
	int next_min;
	int count;
	int min_value;

	min_value = ft_get_min_value(*stack_b);
	next_min = ft_get_next_min(*stack_b, pos);
	count = 0;
	while (*stack_b && min_value != *(int *)(*stack_b)->content)
	{
		if (*stack_b && count < 2 && next_min == *(int *)(*stack_b)->content)
		{
			count++;
			ft_push(stack_a, stack_b, STACK_A);
			if (count == 2)
				ft_swap(stack_a, NULL, STACK_A);
			next_min = ft_get_next_min(*stack_b, pos);
			continue ;
		}
		ft_reverse_rotate(stack_b, NULL, STACK_B);
	}
	ft_post_rotate(stack_a, stack_b, size, count);
}

static void		ft_exec_rbs(t_list **stack_a, t_list **stack_b, int *size,
																		int pos)
{
	int next_min;
	int count;
	int min_value;

	min_value = ft_get_min_value(*stack_b);
	next_min = ft_get_next_min(*stack_b, pos);
	count = 0;
	while (*stack_b && min_value != *(int *)(*stack_b)->content)
	{
		if (*stack_b && count < 2 && next_min == *(int *)(*stack_b)->content)
		{
			count++;
			ft_push(stack_a, stack_b, STACK_A);
			if (count == 2)
				ft_swap(stack_a, NULL, STACK_A);
			next_min = ft_get_next_min(*stack_b, pos);
			continue ;
		}
		ft_rotate(stack_b, NULL, STACK_B);
	}
	ft_post_rotate(stack_a, stack_b, size, count);
}

static int		ft_check_if_sorted(t_list **stack_a, t_list **stack_b, int size)
{
	int i;

	if (ft_is_rev_sorted(*stack_b))
	{
		i = 0;
		while (*stack_b)
		{
			ft_push(stack_a, stack_b, STACK_A);
			i++;
		}
		while (i--)
			ft_rotate(stack_a, NULL, STACK_A);
		return (1);
	}
	else if (ft_is_sorted(*stack_b))
	{
		i = -1;
		while (++i < size)
		{
			ft_push(stack_a, stack_b, STACK_A);
			ft_rotate(stack_a, NULL, STACK_A);
		}
		return (1);
	}
	return (0);
}

void			ft_sort_small(t_list **stack_a, t_list **stack_b, int size,
															int initial)
{
	if (size <= 2)
	{
		ft_place_top(stack_a, stack_b, size);
		return ;
	}
	if (ft_get_min_index(*stack_b) > size / 2)
		ft_exec_rrbs(stack_a, stack_b, &size, ft_get_min_index(*stack_b));
	else
		ft_exec_rbs(stack_a, stack_b, &size, ft_get_min_index(*stack_b));
	if (ft_check_if_sorted(stack_a, stack_b, size) == 0)
		ft_sort_small(stack_a, stack_b, size, initial);
}
