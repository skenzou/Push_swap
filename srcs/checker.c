/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 01:20:57 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/12 03:09:44 by Mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*instructions;
	t_list	*stack_a;
	t_list	*stack_b;
	char	flags;

	if (parse_args(ac, av, &stack_a, &flags) == -1)
		return (!ft_lstdestroy(&stack_a));
	if (read_instructions(&instructions))
		return (ft_lstdestroy(&instructions) == ft_lstdestroy(&stack_a));
	execute_instructions(&stack_a, &stack_b, instructions);
	if (flags & VISU)
		print_lists(stack_a, stack_b, NULL);
	destroy_lists(stack_a, stack_b, instructions);
	return (0);
}
