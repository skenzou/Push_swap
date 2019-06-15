/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:29:04 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 15:10:56 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_sort_3_b(t_list **stack, char dest)
{
	int last;

	while (!ft_is_rev_sorted(*stack))
	{
		last = ft_get_last(*stack);
		if (*((int *)(*stack)->next->content) > *((int *)(*stack)->content))
			ft_swap(stack, NULL, dest);
		else if (last > *((int *)(*stack)->content))
			ft_reverse_rotate(stack, NULL, dest);
		else if (*((int *)(*stack)->next->content) < last)
			ft_reverse_rotate(stack, NULL, dest);
	}
}

void			ft_sort_3(t_list **stack, char dest)
{
	int last;

	if (dest == STACK_A)
	{
		while (!ft_is_sorted(*stack))
		{
			last = ft_get_last(*stack);
			if (*((int *)(*stack)->next->content) < *((int *)(*stack)->content))
				ft_swap(stack, NULL, dest);
			else if (last < *((int *)(*stack)->content))
				ft_reverse_rotate(stack, NULL, dest);
			else if (*((int *)(*stack)->next->content) > last)
				ft_reverse_rotate(stack, NULL, dest);
		}
	}
	else if (dest == STACK_B)
		ft_sort_3_b(stack, dest);
}
