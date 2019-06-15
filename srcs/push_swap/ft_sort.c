/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:25:43 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/16 00:55:49 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			ft_sort_top(t_list **stack_a, int size)
{
	if (size == 1)
		ft_rotate(stack_a, NULL, STACK_A);
	else if (size == 2)
	{
		ft_sort_2(stack_a, STACK_A);
		ft_rotate(stack_a, NULL, STACK_A);
		ft_rotate(stack_a, NULL, STACK_A);
	}
}

#define MEDIAN 0
#define TOP_HALF_LEN 1
#define B_MEDIAN 2

static int			ft_sort_loop(t_list **stack_a, t_list **stack_b,
														int size, int *i)
{
	int data[3];

	data[MEDIAN] = ft_find_median(*stack_a, size);
	data[TOP_HALF_LEN] = 0;
	while (++(*i) < size)
	{
		if (*stack_b)
			data[B_MEDIAN] = ft_find_median(*stack_b, ft_lstsize(*stack_b));
		if (*((int *)(*stack_a)->content) <= data[MEDIAN])
		{
			ft_push(stack_b, stack_a, STACK_B);
			data[TOP_HALF_LEN]++;
		}
		else
		{
			if (*stack_b && *((int *)(*stack_b)->content) <= data[B_MEDIAN]
													&& ft_lstsize(*stack_b) > 5)
				ft_rotate(stack_a, stack_b, BOTH);
			else
				ft_rotate(stack_a, NULL, STACK_A);
		}
		if (ft_check_nbs_left(*stack_a, size - *i, data[MEDIAN]) && ++(*i))
			break ;
	}
	return (data[TOP_HALF_LEN]);
}

static void			ft_apply_rras(t_list **stack_a, t_list **stack_b, int size,
																int b_middle)
{
	int min;

	while (size--)
	{
		min = ft_get_min_index(*stack_b);
		if (min > b_middle)
			ft_reverse_rotate(stack_a, stack_b, BOTH);
		else
			ft_reverse_rotate(stack_a, NULL, STACK_A);
	}
}

static void			ft_post_rras(t_list **stack_a, t_list **stack_b, int b_size,
																	int size)
{
	int save;
	int leftover;
	int i;

	save = *((int *)(*stack_a)->content);
	if (!ft_is_rev_sorted(*stack_b))
		ft_sort_b(stack_a, stack_b, b_size);
	else
	{
		i = -1;
		while (++i < b_size)
			ft_push(stack_a, stack_b, STACK_A);
		i = -1;
		while (++i < b_size)
			ft_rotate(stack_a, stack_b, STACK_A);
	}
	while (!ft_is_size_sorted(*stack_a, ft_size_till_median(*stack_a, save)))
		ft_sort(stack_a, stack_b, ft_size_till_median(*stack_a, save), 0);
	leftover = ft_size_till_median(*stack_a, save);
	while (leftover--)
		ft_rotate(stack_a, NULL, STACK_A);
	if (!ft_is_size_sorted(*stack_a, size - b_size))
		ft_sort(stack_a, stack_b, size - b_size, 0);
}

void				ft_sort(t_list **stack_a, t_list **stack_b, int size,
																	int first)
{
	int top_half_len;
	int index;

	if (size <= 2)
	{
		ft_sort_top(stack_a, size);
		return ;
	}
	index = -1;
	top_half_len = ft_sort_loop(stack_a, stack_b, size, &index);
	if (!first)
		ft_apply_rras(stack_a, stack_b, index - top_half_len, top_half_len / 2);
	ft_post_rras(stack_a, stack_b, top_half_len, size);
}
