/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mohamed <Mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:20:59 by Mohamed           #+#    #+#             */
/*   Updated: 2019/05/31 12:21:55 by Mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Pas le droit aux variables globales finalement :(
// #define NB_INSTRUCTIONS 9
// const char *g_instructions[NB_INSTRUCTIONS] ={
// 	"rra",
// 	"sa",
// 	"sb",
// 	"ss",
// 	"pa",
// 	"pb",
// 	"ra",
// 	"rb",
// 	"rr",
// };

/*
** Tells whether input is a existing instruction.
*/
static int		is_instruction(char *input)
{
	if (ft_strequ("rrb", input))
		return (1);
	if (ft_strequ("rrr", input))
		return (1);
	if (ft_strequ("rra", input))
		return (1);
	if (ft_strequ("sa", input))
		return (1);
	if (ft_strequ("sb", input))
		return (1);
	if (ft_strequ("ss", input))
		return (1);
	if (ft_strequ("pa", input))
		return (1);
	if (ft_strequ("pb", input))
		return (1);
	if (ft_strequ("ra", input))
		return (1);
	if (ft_strequ("rb", input))
		return (1);
	if (ft_strequ("rr", input))
		return (1);
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
			if (is_instruction(input))
				ret = add_to_list(head, (void *)input, ft_strlen(input) + 1);
			else
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
