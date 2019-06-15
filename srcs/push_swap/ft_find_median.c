/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_median.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:17:53 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/16 00:08:40 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					ft_size_till_median(t_list *list, int median)
{
	int i;

	i = 0;
	while (list)
	{
		if (*((int *)list->content) == median)
			return (i);
		list = list->next;
		i++;
	}
	return (i);
}

static int			ft_count_lower_nbs(t_list *stack, int value, int size)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (stack && ++i < size)
	{
		count += *((int *)stack->content) < value;
		stack = stack->next;
	}
	return (count);
}

int					ft_find_median(t_list *stack, int size)
{
	int		half;
	int		value;
	t_list	*list;
	int		i;

	half = size / 2;
	list = stack;
	i = -1;
	while (list && ++i < size)
	{
		value = *((int *)list->content);
		if (ft_count_lower_nbs(stack, value, size) == half)
			return (value);
		list = list->next;
	}
	return (0);
}
