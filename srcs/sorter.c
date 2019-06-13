/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 10:04:50 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/13 22:54:38 by midrissi         ###   ########.fr       */
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
		half = (size / 2) -1;
	else
		half = size / 2;
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

void            sortsmall(t_list **stack_a, t_list **stack_b, int size, int initial)
{
	int         pos;
	int         i;
	int			best_choice;

	if (size <= 1)
	{
		while (size != initial)
		{
			ft_push(stack_a, stack_b, STACK_A);
			size++;
		}
		return ;
	}
	pos = pos_min(*stack_b);
	i = -1;
	best_choice = size / 2;
	//ft_printf("best_choice = %d\n", best_choice);
	if (pos > best_choice)
	{
		// state_stack(&d->a, 'a');
		// ft_printf("pos: %d\n", pos);
		// ft_printf("d->len_a: %d\n", d->len_a);
		while (++i < size - pos)
			ft_reverse_rotate(stack_b, NULL, STACK_B);
		// state_stack(&d->a, 'a');
	}
	else
	{
		while (++i < pos)
			ft_reverse_rotate(stack_b, NULL, STACK_B);
	}
	ft_push(stack_a, stack_b, STACK_A);
	ft_rotate(stack_a, NULL, STACK_A);
	size--;
	sortsmall(stack_a, stack_b, size, initial);
}

int			sorter_b(t_list **stack_a, t_list **stack_b, int size, int initial_size)
{
	int median;
	int i;
	int value;
	int top_half_len;
	int index;
	int min;
	int	sorted;

	(void)initial_size;
	// if (size <= 1)
	// 	return (0);
	if (size <= 5)
	{
		// print_lists(*stack_a, *stack_b, NULL);
		launch_sort(size, stack_a, stack_b, STACK_B);
		i = -1;
		while (++i < size)
			ft_push(stack_a, stack_b, STACK_A);
		i = -1;
		while (++i < size)
			ft_rotate(stack_a, stack_b, STACK_A);
		// print_lists(*stack_a, *stack_b, NULL);
		return (0);
	}
	// else if (size <= 10)
	// {
	// 	sortsmall(stack_a, stack_b, size, size);
	// 	return (0);
	// }
	// if (size == 1)
	// {
	// 	ft_push(stack_a, stack_b, STACK_A);
	// 	ft_rotate(stack_a, NULL, STACK_A);
	// 	return (0);
	// }
	median = find_median(*stack_b, ft_lstsize(*stack_b));
	i = -1;
	top_half_len = 0;
	// min = ft_get_min_value(*stack_b);
	// if (size > 5 && size <= 25)
	// {
	// 	sortsmall(stack_a, stack_b, size, size);
	// 	return ;
	// }
	// if (size == 2)
	// {
	// 	ft_sort_2(stack_b, STACK_B);
	// 	return ;
	// }
	index = -1;
	sorted = 0;
	// ft_printf("=======debut b============\n");
	// ft_printf("size: %d\n", size);
	// ft_printf("median: %d\n", median);
	// ft_printf("min: %d\n", min);
	// print_lists(*stack_a, *stack_b, NULL);
	// ft_printf("=======debut b============\n");
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
	// ft_printf("median: %d\n", median);
	// ft_printf("======AVANT==========\n");
	// 	print_lists(*stack_a, *stack_b, NULL);
	// if (min_index <= size / 2)
	// {
		// int size_2;
		// size_2 = ft_lstsize(*stack_b);
		// if (size_2 <= 5)
		// {
		// 	launch_sort(size, stack_a, stack_b, STACK_B);
		// 	i = -1;
		// 	while (++i < size)
		// 		ft_push(stack_a, stack_b, STACK_A);
		// 	i = -1;
		// 	while (++i < size)
		// 		ft_rotate(stack_a, stack_b, STACK_A);
		// 	return (0);
		// }
		// int test = 0;
		while (++index < size)
		{
			// int size_2;
			// size_2 = ft_lstsize(*stack_b);
			// if (size_2 <= 5)
			// {
			// 	launch_sort(size_2, stack_a, stack_b, STACK_B);
			// 	i = -1;
			// 	while (++i < size_2)
			// 		ft_push(stack_a, stack_b, STACK_A);
			// 	i = -1;
			// 	while (++i < size_2)
			// 		ft_rotate(stack_a, stack_b, STACK_A);
			// 	return (size_2);
			// }
			value = *((int *)(*stack_b)->content);
			if (value == min)
			{
				ft_push(stack_a, stack_b, STACK_A);
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
			// if (check_nbs_left_b(*stack_b, size - index -1, median))
			// {
			// 	index++;
			// 	// print_list(*stack_b, 2);
			// 	// test = 1;
			// 	// ft_printf("ind: %d\n",index - sorted - top_half_len);
			// 	break ;
			// }
		}
	// }
	// else
	// {
	// 	// int size_2;
	// 	// size_2 = ft_lstsize(*stack_b);
	// 	// if (size_2 <= 5)
	// 	// {
	// 	// 	launch_sort(size, stack_a, stack_b, STACK_B);
	// 	// 	i = -1;
	// 	// 	while (++i < size)
	// 	// 		ft_push(stack_a, stack_b, STACK_A);
	// 	// 	i = -1;
	// 	// 	while (++i < size)
	// 	// 		ft_rotate(stack_a, stack_b, STACK_A);
	// 	// 	return (0);
	// 	// }
	// 	ft_printf("size: %d\n", size);
	// 	while (++index < size)
	// 	{
	// 		value = *((int *)(*stack_b)->content);
	// 			ft_printf("value min: %d\n", min);
	// 		if (value == min)
	// 		{
	// 			ft_printf("pa-rra sur %d\n", value);
	// 			ft_push(stack_a, stack_b, STACK_A);
	// 			ft_rotate(stack_a, NULL, STACK_A);
	// 			min = save[i++];
	// 			sorted++;
	// 		}
	// 		else if (value > median)
	// 		{
	// 			ft_printf("pa sur %d\n", value);
	// 			ft_push(stack_a, stack_b, STACK_A);
	// 			top_half_len++;
	// 		}
	// 		else
	// 		{
	// 			ft_reverse_rotate(stack_b, NULL, STACK_B);
	// 			ft_printf("rrb sur %d\n", value);
	// 		}
	// 	}
	// }
	// ft_printf("median: %d\n", median);
	// ft_printf("======APRES==========\n");
	// print_lists(*stack_a, *stack_b, NULL);
	// while (++index < size)
	// {
	// 	value = *((int *)(*stack_b)->content);
	// 	if (value == min)
	// 	{
	// 		ft_push(stack_a, stack_b, STACK_A);
	// 		ft_rotate(stack_a, NULL, STACK_A);
	// 	 	min = save[i++];
	// 		sorted++;
	// 	}
	// 	else if (value > median)
	// 	{
	// 		ft_push(stack_a, stack_b, STACK_A);
	// 		top_half_len++;
	// 	}
	// 	else
	// 		ft_rotate(stack_b, NULL, STACK_B);
	// 	// if (check_nbs_left_b(*stack_b, size - index - 1, median))
	// 	// {
	// 	// 	index++;
	// 	// 	break ;
	// 	// }
	// }
	// ft_printf("index: %d\n", index - sorted - top_half_len);
	// ft_printf("size - sorted - top_half_len: %d\n", size - sorted - top_half_len);
	// ft_printf("=======fin b============\n");
	// ft_printf("top_half_len: %d\n", top_half_len);
	// ft_printf("next_size: %d\n", index - sorted - top_half_len);
	// print_lists(*stack_a, *stack_b, NULL);
	// ft_printf("=======fin b============\n");
	// if (test)
	// 	sorter_b(stack_a, stack_b, ft_lstsize(*stack_b), size);
	// else
	sorted += sorter_b(stack_a, stack_b, size - sorted - top_half_len, size);
	// if (size - top_half_len <= 5)
	// 	launch_sort(size - top_half_len, stack_a, stack_b, STACK_B);
	// if (top_half_len <= 5)
	// 	launch_sort(top_half_len, stack_a, stack_b, STACK_A);
	// (void)initial_size;
	// i = -1;
	// while (++i < size - top_half_len)
	// 	ft_push(stack_a, stack_b, STACK_A);
	if (size == initial_size)
		return (size - sorted);
	return (sorted);
}

// void		sorter(t_list **stack_a, t_list **stack_b, int size)
// {
// 	int median;
// 	int i;
//
// 	median = find_median(*stack_a, size);
// 	i = -1;
// 	while (++i < size)
// }

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
// int			get_last(t_list *list)
// {
// 	int value;
//
// 	while (list)
// 	{
// 		if (!list->next)
// 			value = *(int*)list->content;
// 		list = list->next;
// 	}
// 	return (value);
// }
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
	// ft_printf("==========AVANT BOUCLE========\n");
	// print_lists(*stack_a, *stack_b, NULL);
	// ft_printf("==========AVANT BOUCLE========\n");
	while (++index < size)
	{
		value = *((int *)(*stack_a)->content);
		if (value <= median)
		{
			ft_push(stack_b, stack_a, STACK_B);
			top_half_len++;
		}
		else
			ft_rotate(stack_a, NULL, STACK_A);
		if (check_nbs_left(*stack_a, size - index - 1, median))
		{
			index++;
			break ;
		}
	}
	// ft_printf("==========APRES BOUCLE========\n");
	// print_lists(*stack_a, *stack_b, NULL);
	// ft_printf("==========APRES BOUCLE========\n");
	// if (top_half_len <= 5)
	// 	launch_sort(top_half_len, stack_a, stack_b, STACK_B);
	// else
	// 	sorter_b(stack_b, stack_a, top_half_len, top_half_len);
	if (!first)
	{
		i = -1;
		// int med_b = find_median(*stack_b, top_half_len);
		// int min = ft_get_min_index(*stack_b);
		while (++i < index - top_half_len)
		{
			// if (min > top_half_len / 2)
			// 	ft_reverse_rotate(stack_a, stack_b, BOTH);
			// else
				ft_reverse_rotate(stack_a, NULL, STACK_A);
		}
			// ft_printf("==========APRES RRA========\n");
			// print_lists(*stack_a, *stack_b, NULL);
			// ft_printf("==========APRES RRA========\n");
	}
	// ft_printf("test\n");
	// if (top_half_len > 5)
	// int size = size_till_medial(*stack_a);
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
	// if (*stack_b)
	// 	while (*((int *)(*stack_b)->content) < get_last(*stack_b))
	// 		ft_rotate(stack_b, NULL, STACK_B);
	// if (top_half_len <= 5)
	// {
	// 	i = -1;
	// 	while (++i < top_half_len)
	// 		ft_push(stack_a, stack_b, STACK_A);
	// }
	// ft_printf("===============\n");
	// ft_printf("top_half_len: %d\n", top_half_len);
	// ft_printf("ret: %d\n", ret);
	// print_lists(*stack_a, *stack_b, NULL);
	// ft_printf("===============\n");
	// ft_printf("size_till: %d\n", size_till_median(*stack_a, save));
	// ft_printf("save: %d\n", save);
	while (!is_size_sorted(*stack_a, size_till_median(*stack_a, save)))
		sorter(stack_a, stack_b, size_till_median(*stack_a, save), initial_size, 0);
	if (size == initial_size)
	{
		i = -1;
		// ft_printf("SAVE HAHA:%d\n", save);
		// print_lists(*stack_a, *stack_b, NULL);
		// ft_printf("size - ret: %d\n", size - top_half_len);
		int haha;
		haha = size_till_median(*stack_a, save);
		while (++i < haha)
			ft_rotate(stack_a, NULL, STACK_A);
		// ft_printf("SAVE HAHA:%d\n", save);
		// print_lists(*stack_a, *stack_b, NULL);
		// ft_printf("size - ret: %d\n", size - top_half_len);
		if (!is_size_sorted(*stack_a, size - top_half_len))
		sorter(stack_a, stack_b, size - top_half_len, size - top_half_len, 0);
	}
	if (first)
		ft_rotate(stack_a, NULL, STACK_A);
	// if (!is_size_sorted(*stack_a, size_till_median(*stack_a, save)))
	// 	sorter(stack_a, stack_b, size_till_median(*stack_a, save), initial_size);
	// else
	// {
	// 	ft_printf("FILS DEPUTE\n");
	// 	i = -1;
	// 	while (++i < ret)
	// 		ft_rotate(stack_a, NULL, STACK_A);
	// }
		(void)initial_size;
	// i = -1;
	// while (++i < top_half_len)
	// 	ft_rotate(stack_a, NULL, STACK_A);
	// if (!is_size_sorted(*stack_a, size - top_half_len))
	// 	sorter(stack_a, stack_b, size - top_half_len, initial_size);
	// i = -1;
	// ft_printf("chunk: %d, ret: %d\n", top_half_len, ret);
	// print_list(*stack_a, 1);
	// if (!ret)
	// {
		// while (++i < top_half_len)
		// 	ft_reverse_rotate(stack_a, NULL, STACK_A);
	// }
	// if (!is_botom_sorted(*stack_a, top_half_len))
	// {
	// 	// ft_printf("fdp: %d\n", top_half_len);
	// 	// ft_printf("=======================\n");
	// 	// print_list(*stack_a, 1);
	// 	// ft_printf("=======================\n");
	// 	while (++i < top_half_len)
	// 		ft_reverse_rotate(stack_a, NULL, STACK_A);
	// }

}
