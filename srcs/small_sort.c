/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:24:53 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/10 12:23:21 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 		ft_sort_2(t_list **stack, char dest)
{
	if (!*stack || !(*stack)->next)
		return ;
	if (dest == STACK_A)
	{
		if (*((int *)(*stack)->next->content) < *((int *)(*stack)->content))
			ft_swap(stack, NULL, dest);
	}
	else if (dest == STACK_B)
	{
		if (*((int *)(*stack)->next->content) > *((int *)(*stack)->content))
			ft_swap(stack, NULL, dest);
	}
}

void	ft_sort_3(t_list **stack, char dest)
{
	int last;

	if (dest == STACK_A)
	{
		while (!is_sorted(*stack))
		{
			last = get_last(*stack);
			if (*((int *)(*stack)->next->content) < *((int *)(*stack)->content))
				ft_swap(stack, NULL, dest);
			else if (last < *((int *)(*stack)->content))
				ft_reverse_rotate(stack, NULL, dest);
			else if (*((int *)(*stack)->next->content) > last)
				ft_reverse_rotate(stack, NULL, dest);
		}
	}
	else if (dest == STACK_B)
	{
		while (!is_rev_sorted(*stack))
		{
			last = get_last(*stack);
			if (*((int *)(*stack)->next->content) > *((int *)(*stack)->content))
				ft_swap(stack, NULL, dest);
			else if (last > *((int *)(*stack)->content))
				ft_reverse_rotate(stack, NULL, dest);
			else if (*((int *)(*stack)->next->content) < last)
				ft_reverse_rotate(stack, NULL, dest);
		}
	}
}

void	ft_sort_4(t_list **stack_a, t_list **stack_b, char dest)
{
	int i;

	if (dest == STACK_A)
	{
		i = ft_get_min_index(*stack_a);
		if (i <= 2)
			while (i--)
				ft_rotate(stack_a, NULL, dest);
		else
			while (i++ < 4)
				ft_reverse_rotate(stack_a, NULL, dest);
		ft_push(stack_b, stack_a, STACK_B);
		ft_sort_3(stack_a, STACK_A);
		ft_push(stack_a, stack_b, STACK_A);
	}
	else if (dest == STACK_B)
	{
		i = ft_get_max_index(*stack_b);
		if (i <= 2)
			while (i--)
				ft_rotate(stack_b, NULL, dest);
		else
			while (i++ < 4)
				ft_reverse_rotate(stack_b, NULL, dest);
		ft_push(stack_a, stack_b, STACK_A);
		ft_sort_3(stack_b, STACK_B);
		ft_push(stack_b, stack_a, STACK_B);
	}
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b, char dest)
{
	int i;

	if (dest == STACK_A)
	{
		i = ft_get_min_index(*stack_a);
		if (i <= 2)
			while (i--)
				ft_rotate(stack_a, NULL, dest);
		else
			while (i++ < 5)
				ft_reverse_rotate(stack_a, NULL, dest);
		ft_push(stack_b, stack_a, STACK_B);
		ft_sort_4(stack_a, stack_b, STACK_A);
		ft_push(stack_a, stack_b, STACK_A);
	}
	else if (dest == STACK_B)
	{
		i = ft_get_max_index(*stack_b);
		if (i <= 2)
			while (i--)
				ft_rotate(stack_b, NULL, dest);
		else
			while (i++ < 5)
				ft_reverse_rotate(stack_b, NULL, dest);
		ft_push(stack_a, stack_b, STACK_A);
		ft_sort_4(stack_a, stack_b, STACK_B);
		ft_push(stack_b, stack_a, STACK_B);
	}
}
