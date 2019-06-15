/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:46:31 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 14:51:50 by midrissi         ###   ########.fr       */
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

static int		check_one(char *str, t_list **head)
{
	int ret;
	int number;

	ret = 0;
	if (is_valid_arg(str, &number) && ft_is_not_in_list(number, *head))
		ret = ft_add_to_list(head, &number, sizeof(int *));
	else
		ret = -1;
	if (ret == -1)
		ft_putendl_fd("Error", 2);
	return (ret);
}

int				ft_arg_checker(t_list **head, char *input, int *count)
{
	char	**split;
	int		i;
	int		ret;

	if (!input || !(split = ft_strsplit(input, ' ')))
		return (-1);
	i = -1;
	ret = 0;
	while (split[++i])
		if ((ret = check_one(split[i], head)) == -1)
			break ;
		else
			(*count)++;
	ft_splitdel(split);
	return (ret);
}
