/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:33:08 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 23:59:55 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_launch_sort(int size, t_list **stack_a, t_list **stack_b)
{
	if (ft_is_sorted(*stack_a))
		return ;
	if (size <= 3)
		ft_sort_3(stack_a, STACK_A);
	else if (size == 4)
		ft_sort_4(stack_a, stack_b, STACK_A);
	else if (size == 5)
		ft_sort_5(stack_a, stack_b, STACK_A);
	else
		ft_sort(stack_a, stack_b, size, 1);
}
