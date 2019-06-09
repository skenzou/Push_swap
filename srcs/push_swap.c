/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 09:30:20 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/09 05:59:52 by midrissi         ###   ########.fr       */
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
	sorter(&stack_a, &stack_b, size, size);
	if (flags & VISU)
		print_lists(stack_a, stack_b, NULL);
	return (0);
}
