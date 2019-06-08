/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mohamed <Mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:20:59 by Mohamed           #+#    #+#             */
/*   Updated: 2019/06/08 09:35:33 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const t_instruction	 *get_existing_instructions()
{
	static const t_instruction tab[NB_INSTRUCTIONS] = {
		{"rra", STACK_A, &reverse_rotate_stack},
		{"rrb", STACK_B, &reverse_rotate_stack},
		{"rrr", BOTH, &reverse_rotate_stack},
		{"sa", STACK_A, &swap_two},
		{"sb", STACK_B, &swap_two},
		{"ss", BOTH, &swap_two},
		{"pa", STACK_A, &push_to_second},
		{"pb", STACK_B, &push_to_second},
		{"ra", STACK_A, &rotate_stack},
		{"rb", STACK_B, &rotate_stack},
		{"rr", BOTH, &rotate_stack},
	};
	return (tab);
}

/*
** Tells whether input is a existing instruction.
*/
static int		add_instruction(char *input, t_list **head)
{
	int						i;
	const t_instruction		*instructions;

	i = -1;
	instructions = get_existing_instructions();
	while (++i < NB_INSTRUCTIONS)
		if (ft_strequ(input, instructions[i].op))
			return (add_to_list(head, (void *)&instructions[i],
														sizeof(t_instruction)));
	return (0);
}

int		read_instructions(t_list **head)
{
	char	*input;
	int		ret;

	*head = NULL;
	ret = 1;
	input = NULL;
	while (ret == 1)
	{
		if ((ret = get_next_line(0, &input, '\n')) > 0)
		{
			if ((ret = add_instruction(input, head)) == 0)
			{
				ft_putendl_fd("Error", 2);
				ret = -1;
			}
		}
		ft_strdel(&input);
	}
	if (!ret)
		ft_lstrev(head);
	return (ret);
}
