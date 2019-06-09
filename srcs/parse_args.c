/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mohamed <Mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:17:57 by Mohamed           #+#    #+#             */
/*   Updated: 2019/06/09 06:09:05 by midrissi         ###   ########.fr       */
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

static int		check_one(char *str, t_list **head)
{
	int ret;
	int number;

	ret = 0;
	if (is_valid_arg(str, &number) && is_not_in_list(number, *head))
		ret = add_to_list(head, &number, sizeof(int *));
	else
		ret = -1;
	if (ret == -1)
		ft_putendl_fd("Error", 2);
	return (ret);
}

static	int		check_flags(char ***av, int *ac, char *flags)
{
	if (*ac == 1)
		return (-1);
	if ((*av)[1][0] != '-' || ft_isdigit((*av)[1][1]))
		return (0);
	if (ft_strequ((*av)[1], "-v"))
	{
		(*ac)--;
		(*av)++;
		*flags |= VISU;
		return (0);
	}
	else
	{
		ft_putstr_fd("push_swap/checker: illegal option", 2);
		ft_putendl_fd("\nusage: push_swap/checker [-v] [numbers ...]", 2);
		return (-1);
	}
}

int		parse_args(int ac, char **av, t_list **head, char *flags)
{
	int i;
	int j;
	int count;
	char **split;

	i = 0;
	count = 0;
	if (check_flags(&av, &ac, flags) || ac == 1)
		return (-1);
	while (++i < ac && (j = -1))
	{
		if (!(split = ft_strsplit(av[i], ' ')))
			return (-1);
		while (split[++j])
			if (check_one(split[j], head) == -1)
			{
				ft_splitdel(split);
				return (-1);
			}
			else
				count++;
		ft_splitdel(split);
	}
	ft_lstrev(head);
	return (count);
}
