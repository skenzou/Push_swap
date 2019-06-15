/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:24:53 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 15:05:01 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_sort_2(t_list **stack, char dest)
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
