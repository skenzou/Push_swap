/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 01:20:57 by midrissi          #+#    #+#             */
/*   Updated: 2019/05/31 16:44:24 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		main(int ac, char **av)
{
	t_list	*instructions;
	t_list	*stack_a;
	t_list	*stack_b;

	if (parse_args(ac, av, &stack_a))
		return (!ft_lstdestroy(&stack_a));
	if (read_instructions(&instructions))
		return (ft_lstdestroy(&instructions) == ft_lstdestroy(&stack_a));
	execute_instructions(&stack_a, &stack_b, instructions);
	print_lists(stack_a, stack_b, instructions);
	destroy_lists(stack_a, stack_b, instructions);
	return (0);
}
