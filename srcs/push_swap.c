/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:30:20 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/08 10:53:45 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list		*instructions;
	t_list		*stack_a;
	t_list		*stack_b;

	if (parse_args(ac,av, &stack_a))
		return (!ft_lstdestroy(&stack_a));
	stack_b = NULL;
	instructions = NULL;
	sorter(&stack_a, &stack_b, ac -1);
	print_lists(stack_a, stack_b, instructions);
	return (0);
}
