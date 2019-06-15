/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:28:31 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 15:09:43 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_sort_4_b(t_list **stack_a, t_list **stack_b, char dest)
{
	int i;

	i = ft_get_max_index(*stack_b);
	if (i <= 2)
		while (i--)
			ft_rotate(stack_b, NULL, dest);
	else
		while (i++ < 4)
			ft_reverse_rotate(stack_b, NULL, dest);
	if (!ft_is_rev_sorted(*stack_b))
	{
		ft_push(stack_a, stack_b, STACK_A);
		ft_sort_3(stack_b, STACK_B);
		ft_push(stack_b, stack_a, STACK_B);
	}
}

void			ft_sort_4(t_list **stack_a, t_list **stack_b, char dest)
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
		if (!ft_is_sorted(*stack_a))
		{
			ft_push(stack_b, stack_a, STACK_B);
			ft_sort_3(stack_a, STACK_A);
			ft_push(stack_a, stack_b, STACK_A);
		}
	}
	else if (dest == STACK_B)
		ft_sort_4_b(stack_a, stack_b, dest);
}
