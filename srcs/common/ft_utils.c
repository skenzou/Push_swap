/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mohamed <Mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:19:41 by Mohamed           #+#    #+#             */
/*   Updated: 2019/06/15 13:25:06 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Creates a new node and add it to my list.
*/

int				ft_add_to_list(t_list **head, void *data, size_t size)
{
	t_list *node;

	if (!(node = ft_lstnew(data, size)))
		return (-1);
	ft_lstadd(head, node);
	return (1);
}

static void		ft_print_list(t_list *list, char number)
{
	int i;

	i = 0;
	if (number == 1)
		ft_printf(
		ANSI_BBLUE"========================STACK_A=========================\n");
	else if (number == 2)
		ft_printf(
		ANSI_BRED"========================STACK_B=========================\n");
	else
		ft_printf(
		ANSI_BCYAN"======================INSTRUCTIONS======================\n");
	while (list)
	{
		if (number)
			ft_printf("number[%d]: %d\n", i++, *((int *)list->content));
		else
			ft_printf("instruction[%d]: %s\n", i++,
								((t_instruction *)list->content)->op);
		list = list->next;
	}
	ft_printf(
		"========================================================\n"ANSI_RESET);
}

void			ft_print_lists(t_list *stack_a, t_list *stack_b,
														t_list *instructions)
{
	ft_print_list(stack_a, 1);
	if (stack_b)
		ft_print_list(stack_b, 2);
	if (instructions)
		ft_print_list(instructions, 0);
}

void			ft_destroy_lists(t_list *stack_a, t_list *stack_b,
														t_list *instructions)
{
	ft_lstdestroy(&stack_a);
	ft_lstdestroy(&stack_b);
	ft_lstdestroy(&instructions);
}

int				ft_is_not_in_list(int number, t_list *list)
{
	while (list)
	{
		if (number == *((int *)list->content))
			return (0);
		list = list->next;
	}
	return (1);
}
