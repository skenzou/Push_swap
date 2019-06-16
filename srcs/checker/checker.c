/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 01:20:57 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/16 10:56:07 by Mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_list	*instructions;
	t_list	*stack_a;
	t_list	*stack_b;
	char	flags;

	if (ft_parse_args(ac, av, &stack_a, &flags) == -1)
		return (!ft_lstdestroy(&stack_a));
	if (ft_read_instructions(&instructions, NULL))
		return (ft_lstdestroy(&instructions) == ft_lstdestroy(&stack_a));
	stack_b = NULL;
	ft_execute_instructions(&stack_a, &stack_b, instructions, (flags & VISU));
	ft_destroy_lists(stack_a, stack_b, instructions);
	return (0);
}
