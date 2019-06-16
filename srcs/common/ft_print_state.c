/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mohamed <Mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 10:29:15 by Mohamed           #+#    #+#             */
/*   Updated: 2019/06/16 11:15:34 by Mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_print_state(t_list *stack_a, t_list *stack_b)
{
	ft_printf(ANSI_BBLUE"==============STACK_A=============="ANSI_RESET);
	ft_printf(ANSI_BCYAN"||"ANSI_RESET);
	ft_printf(ANSI_BRED"==============STACK_B==============\n"ANSI_RESET);
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf(ANSI_BBLUE"%*d"ANSI_RESET, 18, *(int *)stack_a->content);
			ft_printf("%*c", 17,' ');
			stack_a = stack_a->next;
		}
		else
			ft_printf("%*c", 35, ' ');
		ft_printf(ANSI_BCYAN"||"ANSI_RESET);
		if (stack_b)
		{
			ft_printf(ANSI_BRED"%*d"ANSI_RESET, 18, *(int *)stack_b->content);
			ft_printf("%*c", 17,' ');
			stack_b = stack_b->next;
		}
		ft_putchar('\n');
	}
	ft_printf(ANSI_BBLUE"==================================="ANSI_RESET);
	ft_printf(ANSI_BCYAN"||"ANSI_RESET);
	ft_printf(ANSI_BRED"===================================\n"ANSI_RESET);
}
