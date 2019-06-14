/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:04:50 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/14 19:36:04 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			count_lower_nbs(t_list *stack, int value, int size)
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

static int			find_median(t_list *stack, int size)
{
	int half;
	int value;
	t_list *list;
	int i;

	if (size % 2 == 0)
		half = (size / 2);
	else
		half = size / 2;
	// if (size < 100 && size > 40)
	// 	half = 20;
	// if (size < 100)
	// 	half = size * 3/ 4;
	// if (size >= 300)
	// 	half = size / 2;
	list = stack;
	i = -1;
	while (list && ++i < size)
	{
		value = *((int *)list->content);
		if (count_lower_nbs(stack, value, size) == half)
			return (value);
		list = list->next;
	}
	ft_printf("CAREFUL UNEXPECTED ERROR: size -> %d\n", size);
	print_list(stack, 1);
	exit(1);
	return (0);
}

static int		is_size_sorted(t_list *stack, int size)
{
	int i;

	i = -1;
	while (stack && stack->next && ++i < size)
	{
		if ((*(int *)stack->content) > (*(int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int			check_nbs_left(t_list *stack, int size, int median)
{
	int i;
	t_list *save;
	int count;

	i = -1;
	save = stack;
	count = 0;
	while (++i < size)
	{
		if (*((int *)stack->content) <= median)
			return (0);
		stack = stack->next;
	}
	// if (count < 2 && size > 10)
	// 	return (1);
	// if (count == 0)
	// 	return (1);
	// if (count < 5 && size > 50)
	// 	return (1);
	return (1);
}

int			check_nbs_left_b(t_list *stack, int size, int median)
{
	int i;
	t_list *save;

	i = -1;
	save = stack;
	while (++i < size)
	{
		if (*((int *)stack->content) > median)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void launch_sort(int size, t_list **stack_a, t_list **stack_b, char dest)
{
	if (dest == STACK_A)
	{
		if (size <= 3)
			ft_sort_3(stack_a, STACK_A);
		else if (size == 4)
			ft_sort_4(stack_a, stack_b, STACK_A);
		else if (size == 5)
			ft_sort_5(stack_a, stack_b, STACK_A);
	}
	else if (dest == STACK_B && !is_rev_sorted(*stack_b))
	{
		if (size <= 3)
			ft_sort_3(stack_b, STACK_B);
		else if (size == 4)
			ft_sort_4(stack_a, stack_b, STACK_B);
		else if (size == 5)
			ft_sort_5(stack_a, stack_b, STACK_B);
	}
}

int		get_min_from_tab(int *tab, int size)
{
	int i;
	int min;

	if (!size)
		return (-2147483648);
	i = 0;
	min = tab[0];
	while (++i < size)
		if (min > tab[i])
			min = tab[i];
	return (min);
}

int		check_insert(t_list *list, int last, int current)
{
	while (list)
	{
		if (*((int *)list->content) > last && *((int *)list->content) < current)
			return (1);
		list = list->next;
	}
	return (0);
}

int		is_botom_sorted(t_list *list, int chunk)
{
	int size;
	int i;
	int min;
	int sorted;
	int last;
	t_list *save;

	if (chunk == 0 || !list)
		return (1);
	size = ft_lstsize(list);
	size = size - chunk;
	i = -1;
	min = *((int *)list->content);
	save = list;
	while (++i < size && list)
	{
		if (min > *((int *)list->content))
			min = *((int *)list->content);
		list = list->next;
	}
	if (list)
	{

		sorted = *((int *)list->content);
		last = *((int *)list->content);
	// ft_printf("start: %d\n", sorted);
}
	while (list)
	{
		if (check_insert(save, last, *((int *)list->content)))
			return (0);
		if (*((int *)list->content) < sorted)
			return (0);
		last = *((int *)list->content);
		list = list->next;
	}
	return (1);
}

int				pos_min(t_list *stack)
{
	t_list	*list;
	int		min;
	int     i;
	int		pos_min;

	i = 0;
	pos_min = 0;
	list = stack;
	min = *(int *)stack->content;
	while (list)
	{
		if (*(int *)list->content < min)
		{
			pos_min = i;
			min = *(int *)list->content;
		}
		list = list->next;
		i++;
	}
	return (pos_min);
}

int				get_next_min(t_list *list, int oldmin)
{
	int min;
	int i;

	if (oldmin != 0)
		min = *(int *)list->content;
	else
		min = *(int *)list->next->content;
	i = 0;
	while (list)
	{
		if (*(int *)list->content < min && i != oldmin)
			min = *(int *)list->content;
		i++;
		list = list->next;
	}
	return (min);
}

void            sortsmall(t_list **stack_a, t_list **stack_b, int size, int initial)
{
	int         pos;
	int         i;
	int			best_choice;


	if (size == 2)
	{
		ft_sort_2(stack_b, STACK_B);
		ft_push(stack_a, stack_b, STACK_A);
		ft_push(stack_a, stack_b, STACK_A);
		ft_rotate(stack_a, stack_b, STACK_A);
		ft_rotate(stack_a, stack_b, STACK_A);
		return ;
	}
	if (size <= 1 && *stack_b)
	{
		// print_lists(*stack_a, *stack_b, NULL);
		int lstsize = ft_lstsize(*stack_b);
		int j = -1;
		while (++j < lstsize)
		{
			ft_push(stack_a, stack_b, STACK_A);
			ft_rotate(stack_a, NULL, STACK_A);
		}
		// print_lists(*stack_a, *stack_b, NULL);
		return ;
	}
	pos = pos_min(*stack_b);
	// print_list(*stack_b, 2);
	// ft_printf("pos of min: %d\n", pos);
	i = -1;
	best_choice = size / 2;
	// ft_printf("best_choice: %d\n", best_choice);
	//ft_printf("best_choice = %d\n", best_choice);
	int next_min = get_next_min(*stack_b, pos);
	int count = 0;
	// ft_printf("next_min: %d\n", next_min);
	// print_list(*stack_b, 2);
	int min_value = ft_get_min_value(*stack_b);
	if (pos > best_choice)
	{
		// state_stack(&d->a, 'a');
		// ft_printf("pos: %d\n", pos);
		// ft_printf("d->len_a: %d\n", d->len_a);

		while (*stack_b && min_value != *(int *)(*stack_b)->content)
		{
			if (*stack_b && count < 2 && next_min == *(int *)(*stack_b)->content)
			{
				// ft_printf("0001\n");
				count++;
				ft_push(stack_a, stack_b, STACK_A);
				// ft_printf("00002\n");
				if (count == 2)
					ft_swap(stack_a, NULL, STACK_A);
				// ft_printf("0003\n");
				get_next_min(*stack_b, pos);
				// i++;
				continue ;
				// ft_printf("0004\n");
			}
			ft_reverse_rotate(stack_b, NULL, STACK_B);
		}
		// state_stack(&d->a, 'a');
	}
	else
	{
		while (*stack_b && min_value != *(int *)(*stack_b)->content)
		{
			if (*stack_b && count < 2 && next_min == *(int *)(*stack_b)->content)
			{
				count++;
				// ft_printf("11111\n");
				ft_push(stack_a, stack_b, STACK_A);
				// ft_printf("11112\n");
				if (count == 2)
					ft_swap(stack_a, NULL, STACK_A);
				// ft_printf("11113\n");
				get_next_min(*stack_b, pos);
				// i++;
				continue ;
				// ft_printf("11114\n");
			}
			ft_rotate(stack_b, NULL, STACK_B);
		}
	}
	// ft_printf("NB to push: %d\n", *(int *)(*stack_b)->content);
	// print_lists(*stack_a, *stack_b, NULL);
	size--;
	ft_push(stack_a, stack_b, STACK_A);
	int min = ft_get_min_index(*stack_b);
	if (*stack_b && min < size / 2)
	{
		ft_rotate(stack_a, NULL, BOTH);
		ft_rotate(stack_b, NULL, NO_WRITE);
	}
	else
		ft_rotate(stack_a, NULL, STACK_A);
	if (count)
	{
		// ft_printf("test\n");
		while (count--)
		{
			ft_rotate(stack_a, NULL, STACK_A);
			size--;
		}
	}
	if (is_rev_sorted(*stack_b))
	{
		int k = 0;
		while (*stack_b)
		{
			ft_push(stack_a, stack_b, STACK_A);
			k++;
		}
		while (k--)
			ft_rotate(stack_a, NULL, STACK_A);
		return ;
	}
	if (!is_sorted(*stack_b))
		sortsmall(stack_a, stack_b, size, initial);
	else
	{
		// ft_printf("size: %d\n", size);
		// print_lists(*stack_a, *stack_b, NULL);
		i = -1;
		while (++i < size)
		{
			ft_push(stack_a, stack_b, STACK_A);
			ft_rotate(stack_a, NULL, STACK_A);
		}
		// print_lists(*stack_a, *stack_b, NULL);
		// i = -1;
		// while (++i < size)
		// 	ft_rotate(stack_a, NULL, STACK_A);
	}
}

void		sorter_b(t_list **stack_a, t_list **stack_b, int size, int initial_size)
{
	int median;
	int i;
	int value;
	int top_half_len;
	int index;
	int min;
	int	sorted;

	if (size <= 30)
	{
		sortsmall(stack_a, stack_b, size, size);
		return ;
	}
		(void)initial_size;
	median = find_median(*stack_b, ft_lstsize(*stack_b));
	i = -1;
	top_half_len = 0;
	index = -1;
	sorted = 0;
	int *save;
	int size_b;
	t_list *tmp;
	size_b = ft_lstsize(*stack_b);
	save = ft_memalloc(sizeof(int) * size_b);
	tmp = *stack_b;
	i = 0;
	while (tmp)
	{
		save[i++] = *((int *)tmp->content);
		tmp = tmp->next;
	}
	i = 0;
	sort_tab(save, size);
	min = save[i++];
	int min_index;
	min_index = ft_get_min_index(*stack_b);
	while (++index < size)
	{
		value = *((int *)(*stack_b)->content);
		if (value == min)
		{
			ft_push(stack_a, stack_b, STACK_A);
			if (*((int *)(*stack_b)->content) != save[i] && *((int *)(*stack_b)->content) <= median)
			{
				ft_rotate(stack_a, NULL, BOTH);
				ft_rotate(stack_b, NULL, NO_WRITE);
			}
			else
				ft_rotate(stack_a, NULL, STACK_A);
				min = save[i++];
				sorted++;
		}
		else if (value > median)
		{
			ft_push(stack_a, stack_b, STACK_A);
			top_half_len++;
		}
		else
			ft_rotate(stack_b, NULL, STACK_B);
		if (check_nbs_left_b(*stack_b, ft_lstsize(*stack_b), median))
		{
			break ;
		}
	}
	sorter_b(stack_a, stack_b, ft_lstsize(*stack_b), size);
}

int			get_first(t_list *list, int size)
{
	int i;

	i = -1;
	while (++i < size && list)
		list = list->next;
	return (*((int *)list->content));
}

int			size_till_median(t_list *list, int median)
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

void		sorter(t_list **stack_a, t_list **stack_b, int size, int initial_size, int first)
{
	int median;
	int i;
	int value;
	int top_half_len;
	int index;
	int ret;

	if (size <= 1)
		return ;
	median = find_median(*stack_a, size);
	i = -1;
	top_half_len = 0;
	if (size == 2)
	{
		ft_sort_2(stack_a, STACK_A);
		ft_rotate(stack_a, stack_b, STACK_A);
		ft_rotate(stack_a, stack_b, STACK_A);
		return ;
	}
	index = -1;
	int tmp_med;
	while (++index < size)
	{
		if (*stack_b)
			tmp_med = find_median(*stack_b, ft_lstsize(*stack_b));
		value = *((int *)(*stack_a)->content);
		if (value <= median)
		{
			ft_push(stack_b, stack_a, STACK_B);
			top_half_len++;
		}
		else
		{
			if (*stack_b && *((int *)(*stack_b)->content) <= tmp_med && ft_lstsize(*stack_b) > 5)
			{
				ft_rotate(stack_a, NULL, BOTH);
				ft_rotate(stack_b, NULL, NO_WRITE);
			}
			else
				ft_rotate(stack_a, NULL, STACK_A);
		}
		if (check_nbs_left(*stack_a, size - index, median))
		{
			index++;
			break ;
		}
	}
	if (!first)
	{
		i = -1;
		int min;
		min = ft_get_min_index(*stack_b);
		while (++i < index - top_half_len)
		{
			min = ft_get_min_index(*stack_b);
			if (min > top_half_len / 2)
			{
				ft_reverse_rotate(stack_a, NULL, BOTH);
				ft_reverse_rotate(stack_b, NULL, NO_WRITE);
			}
			else
				ft_reverse_rotate(stack_a, NULL, STACK_A);
		}
	}
	(void)ret;
	int save = *((int *)(*stack_a)->content);
	if (!is_rev_sorted(*stack_b))
		sorter_b(stack_a, stack_b, top_half_len, top_half_len);
	else
	{
		i = -1;
		while (++i < top_half_len)
			ft_push(stack_a, stack_b, STACK_A);
		i = -1;
		while (++i < top_half_len)
			ft_rotate(stack_a, stack_b, STACK_A);
	}
	while (!is_size_sorted(*stack_a, size_till_median(*stack_a, save)))
		sorter(stack_a, stack_b, size_till_median(*stack_a, save), initial_size, 0);
	if (size == initial_size)
	{
		i = -1;
		int haha;
		haha = size_till_median(*stack_a, save);
		while (++i < haha)
			ft_rotate(stack_a, NULL, STACK_A);
		if (!is_size_sorted(*stack_a, size - top_half_len))
		sorter(stack_a, stack_b, size - top_half_len, size - top_half_len, 0);
	}
		(void)initial_size;

}
