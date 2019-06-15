/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:04:50 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 21:50:32 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		*ft_create_tab(t_list *stack_a, t_list *stack_b)
{
	int *tab;
	int i;

	if (!(tab = (int *)ft_memalloc(sizeof(int) * ft_lstsize(stack_b))))
	{
		ft_destroy_lists(stack_a, stack_b, NULL);
		exit(1);
	}
	i = 0;
	while (stack_b)
	{
		tab[i++] = *((int *)stack_b->content);
		stack_b = stack_b->next;
	}
	ft_sort_tab(tab, i);
	return (tab);
}

static int		ft_exec_right_instruction(t_list **stack_a, t_list **stack_b,
														int median, int **tab)
{
	if (*((int *)(*stack_b)->content) == **tab)
	{
		ft_push(stack_a, stack_b, STACK_A);
		if (*((int *)(*stack_b)->content) != *((*tab) + 1)
						&& *((int *)(*stack_b)->content) <= median)
			ft_rotate(stack_a, stack_b, BOTH);
		else
			ft_rotate(stack_a, NULL, STACK_A);
		(*tab)++;
	}
	else if (*((int *)(*stack_b)->content) > median)
		ft_push(stack_a, stack_b, STACK_A);
	else
		ft_rotate(stack_b, NULL, STACK_B);
	if (ft_check_nbs_left_b(*stack_b, ft_lstsize(*stack_b), median))
		return (1);
	return (0);
}

void			ft_sort_b(t_list **stack_a, t_list **stack_b, int size)
{
	int		*tab;
	int		median;
	int		*copy;

	if (size <= 30)
	{
		ft_sort_small(stack_a, stack_b, size, size);
		return ;
	}
	median = ft_find_median(*stack_b, ft_lstsize(*stack_b));
	tab = ft_create_tab(*stack_a, *stack_b);
	copy = tab;
	while (size--)
	{
		if (ft_exec_right_instruction(stack_a, stack_b, median, &tab))
			break ;
	}
	free(copy);
	ft_sort_b(stack_a, stack_b, ft_lstsize(*stack_b));
}
