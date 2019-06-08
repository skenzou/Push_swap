/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 21:11:44 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/08 08:47:30 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		is_valid_arg(char *str, int *number)
{
	int signe;
	int len;

	*number = ft_atoi(str);
	if ((signe = *str == '-') || *str == '+')
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

static int		is_not_in_stack(int number, t_int_node *stack_a)
{
	int i;
	int size;

	i = -1;
	size = stack_a[0].size;
	while (++i < size)
		if (stack_a[i].set && stack_a[i].value == number)
			return (0);
	return (1);
}

t_int_node		*parse_args(int ac, char **av)
{
	int			i;
	int			number;

	i = 0;
	if (ac == 1)
		return (NULL);
	if (!(stack_a = init_stack(ac - 1)))
		return (NULL);
	while (++i < ac)
		if (is_valid_arg(av[i], &number) && is_not_in_stack(number, stack_a))
			set_node(&stack_a[i - 1], number);
		else
		{
			ft_putendl_fd("Error", 2);
			free(stack_a);
			return (NULL);
		}
	return (stack_a);
}
