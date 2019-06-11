/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:46:33 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/11 09:48:04 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_min_value(t_list *stack)
{
	int value;

	if (!stack)
		return (0);
	value = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < value)
			value = *(int *)stack->content;
		stack = stack->next;
	}
	return (value);
}

int		ft_get_max_value(t_list *stack)
{
	int value;

	if (!stack)
		return (0);
	value = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > value)
			value = *(int *)stack->content;
		stack = stack->next;
	}
	return (value);
}
