/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 04:47:17 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/08 22:37:19 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			count_lower_nbs(t_int_node *stack, int value, int size)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (++i < size)
		count += stack[i].value < value;
	return (count);
}

static int			find_median(t_int_node *stack)
{
	int size;
	int half;
	int i;

	size = stack[0].size;
	if (size % 2 == 0)
		half = (size / 2) -1;
	else
		half = size / 2;
	i = -1;
	while (count_lower_nbs(stack, stack[++i].value, size) != half)
		continue ;
	return (stack[i].value);
}

void		sorter(t_int_node *stack_a, t_int_node *stack_b)
{
	(void)stack_b;
	ft_printf("median: %d\n", find_median(stack_a));
}

void sorter(int n)
{
	int top_half_len;
	int median;
	int i;

	if (n == 1)
		return;
	i = -1;
	median = stack_a[find_median(stack_a)]; //it's up to you to determine the best way to do this
	while (++i < n)
	{
		if (stack_a[i] > median)
		{
			push(stack_a)
			top_half_len++;
		}
	}
    for 0 to n {    //filter all values above the median into list 2
        if (value > median) {
            push list 1 top to list 2 //list 2 stores the larger half
            top_half_len++
        }
        rotate list 1 forward
    }

    //reverse the list back to original position
    rotate list 1 backward (n - top_half_len) times

    //push larger half onto smaller half
    push list 2 top to list 1 top_half_len times

    //recursively call this on the larger half
    quicksort(top_half_len)

    //rotate smaller half to front
    rotate list 1 forward top_half_len times

    //recursively call this on smaller half
    quicksort(n - top_half_len)

    //reverse list back to original position
    //rotate list 1 backward top_half_len times
}
