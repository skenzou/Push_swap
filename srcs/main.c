/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 01:20:57 by midrissi          #+#    #+#             */
/*   Updated: 2019/05/31 03:43:26 by Mohamed          ###   ########.fr       */
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
int		is_instruction(char *input)
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

/*
** Creates a new node and add it to my list.
*/
int		add_to_list(t_list **head, void *data, size_t size)
{
	t_list *node;

	if (!(node = ft_lstnew(data, size)))
		return (-1);
	ft_lstadd(head, node);
	return (1);
}

void	print_list(t_list *list, char number)
{
	int i;

	i = 0;
	if (number)
		ft_printf("==============================STACK_%c===============================\n", '@' + number);
	else
		ft_printf("============================INSTRUCTIONS============================\n");
	while(list)
	{
		if (number)
			ft_printf("number[%d]: %d\n", i++, *((int *)list->content));
		else
			ft_printf("instruction[%d]: %s\n", i++, (char *)list->content);
		list = list->next;
	}
	ft_printf("====================================================================\n");
}

int		read_instructions(t_list **head)
{
	char	*input;
	int		ret;

	*head = NULL;
	ret = 1;
	while (ret == 1)
	{
		input = NULL;
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
	}
	if (!ret)
		ft_lstrev(head);
	return (ret);
}

int		is_valid_arg(char *str, int *number)
{
	int signe;
	int len;

	*number = ft_atoi(str);
	if ((signe = *str == '-'))
		str++;
	if (ft_isonly_digit(str) == 0)
		return (0);
	while (*str == '0')
		str++;
	len = ft_strlen(str);
	if (len > 10 || (len == 10 && *str > '2'))
		return (0);
	return (!((signe && *number > 0) || (!signe && *number < 0)));
}

int		is_not_in_list(int number, t_list *list)
{
	while (list)
	{
		if (number == *((int *)list->content))
			return (0);
		list = list->next;
	}
	return (1);
}

int		parse_args(int ac, char **av, t_list **head)
{
	int i;
	int number;

	i = 0;
	*head = NULL;
	while (++i < ac)
	{
		if (is_valid_arg(av[i], &number) && is_not_in_list(number, *head))
		{
			if (add_to_list(head, &number, sizeof(int *)) == - 1)
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_list	*instructions;
	t_list	*stack_a;
	// t_list	*stack_b;

	if (parse_args(ac, av, &stack_a))
		return (!ft_lstdestroy(&stack_a));
	if (read_instructions(&instructions))
		return (ft_lstdestroy(&instructions) == ft_lstdestroy(&stack_a));
	print_list(stack_a, 1);
	print_list(instructions, 0);
	(void)ac;
	(void)av;
	return (0);
}
