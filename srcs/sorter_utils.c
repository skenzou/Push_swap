/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:28:15 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/10 11:57:08 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_min_index(t_list *stack)
{
	int i;
	int index;
	int value;

	if (!stack)
		return (0);
	i = 0;
	index = 0;
	value = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content < value)
		{
			value = *(int *)stack->content;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int		ft_get_max_index(t_list *stack)
{
	int i;
	int index;
	int value;

	i = 0;
	index = 0;
	value = *(int *)stack->content;
	while (stack)
	{
		if (*(int *)stack->content > value)
		{
			index = i;
			value = *(int *)stack->content;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int		get_last(t_list *list)
{
	if (!list)
		return (0);
	while (list && list->next)
		list = list->next;
	return (*((int *)(list)->content));
}

int		is_rev_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if ((*(int *)stack->content) < (*(int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}
