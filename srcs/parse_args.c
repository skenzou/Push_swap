/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mohamed <Mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:17:57 by Mohamed           #+#    #+#             */
/*   Updated: 2019/05/31 13:32:15 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		is_valid_arg(char *str, int *number)
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

static int		is_not_in_list(int number, t_list *list)
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
	if (ac == 1)
		return (1);
	while (++i < ac)
	{
		if (is_valid_arg(av[i], &number) && is_not_in_list(number, *head))
		{
			if (add_to_list(head, &number, sizeof(int *)) == - 1)
				return (1);
		}
		else
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
	}
	ft_lstrev(head);
	return (0);
}
