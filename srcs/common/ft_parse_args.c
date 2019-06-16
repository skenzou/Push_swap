/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mohamed <Mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:17:57 by Mohamed           #+#    #+#             */
/*   Updated: 2019/06/16 10:27:33 by Mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		ft_check_flags(char ***av, int *ac, char *flags)
{
	char *str;

	if (*ac == 1)
		return (-1);
	if ((*av)[1][0] != '-' || ft_isdigit((*av)[1][1]))
		return (0);
	str = ((*av)[1]) + 1;
	while (*str)
	{
		if (*str == 'f')
			*flags |= FROM_FILE;
		else if (*str == 'v')
			*flags |= VISU;
		else
		{
			ft_putstr_fd("push_swap/checker: illegal option", 2);
			ft_putendl_fd("\nusage: push_swap/checker [-vf] [numbers ...]", 2);
			return (-1);
		}
		str++;
	}
	(*ac)-- && (*av)++;
	return (0);
}

int				ft_parse_args(int ac, char **av, t_list **head, char *flags)
{
	int i;
	int count;

	i = 0;
	count = 0;
	*flags = 0;
	*head = NULL;
	if (ft_check_flags(&av, &ac, flags) || ac == 1)
		return (-1);
	if (*flags & FROM_FILE)
		return (ft_read_from_file(av[1], head));
	while (++i < ac)
		if (ft_arg_checker(head, av[i], &count) == -1)
			return (-1);
	ft_lstrev(head);
	return (count);
}
