/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mohamed <Mohamed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 12:19:41 by Mohamed           #+#    #+#             */
/*   Updated: 2019/05/31 12:20:02 by Mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
