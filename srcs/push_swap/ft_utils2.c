/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:28:46 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/16 00:04:16 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_get_next_min(t_list *list, int oldmin)
{
	int min;
	int i;

	if (oldmin != 0)
		min = *(int *)list->content;
	else
		min = *(int *)list->next->content;
	i = 0;
	while (list)
	{
		if (*(int *)list->content < min && i != oldmin)
			min = *(int *)list->content;
		i++;
		list = list->next;
	}
	return (min);
}

int			ft_is_size_sorted(t_list *stack, int size)
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

int			ft_check_nbs_left(t_list *stack, int size, int median)
{
	int			i;
	t_list		*save;
	int			count;

	i = -1;
	save = stack;
	count = 0;
	while (++i < size && stack)
	{
		if (*((int *)stack->content) <= median)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int			ft_check_nbs_left_b(t_list *stack, int size, int median)
{
	int			i;
	t_list		*save;

	i = -1;
	save = stack;
	while (++i < size)
	{
		if (*((int *)stack->content) > median)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void		ft_place_top(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		ft_sort_2(stack_b, STACK_B);
		ft_push(stack_a, stack_b, STACK_A);
		ft_push(stack_a, stack_b, STACK_A);
		ft_rotate(stack_a, stack_b, STACK_A);
		ft_rotate(stack_a, stack_b, STACK_A);
	}
	else if (size == 1)
	{
		ft_push(stack_a, stack_b, STACK_A);
		ft_rotate(stack_a, NULL, STACK_A);
	}
}
