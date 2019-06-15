/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:46:33 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 13:34:52 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			ft_get_min_index(t_list *stack)
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

int			ft_get_max_index(t_list *stack)
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

int			ft_get_last(t_list *list)
{
	if (!list)
		return (0);
	while (list && list->next)
		list = list->next;
	return (*((int *)(list)->content));
}

int			ft_is_rev_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if ((*(int *)stack->content) < (*(int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

void		ft_sort_tab(int *tab, int size)
{
	int swap;
	int i;
	int temp;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (++i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
				swap = 1;
			}
		}
	}
}
