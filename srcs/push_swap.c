/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:30:20 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/13 20:23:41 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	char		flags;
	int			size;

	stack_a = NULL;
	if ((size = parse_args(ac, av, &stack_a, &flags)) == -1)
		return (!ft_lstdestroy(&stack_a));
	stack_b = NULL;
	if (size <= 3)
		ft_sort_3(&stack_a, STACK_A);
	else if (size == 4)
		ft_sort_4(&stack_a, &stack_b, STACK_A);
	else if (size == 5)
		ft_sort_5(&stack_a, &stack_b, STACK_A);
	else
		sorter(&stack_a, &stack_b, size, size, 1);
	// if (size > 5)
	// 	ft_rotate(&stack_a, NULL, STACK_A);
	if (flags & VISU)
		print_lists(stack_a, stack_b, NULL);
	destroy_lists(stack_a, stack_b, NULL);
	return (0);
}
