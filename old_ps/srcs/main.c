/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 23:27:32 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/08 08:21:05 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	// t_list	*instructions;
	t_stack		stack_a;
	t_stack		stack_b;

	if (init_stacks(&stack_a, &stack_b, ac - 1))
		return (1);
	if (parse_args(&stack_a, ac, av)))
		return (1);
	if (!(stack_b = init_stack(stack_a[0].size)))
		return (1);
	print_stack(stack_a, 'A');
	print_stack(stack_b, 'B');
	sorter(stack_a, stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
