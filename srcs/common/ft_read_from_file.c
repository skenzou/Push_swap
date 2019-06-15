/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_from_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 12:27:03 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 13:11:02 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_read_from_file(char *file, t_list **head)
{
	int		fd;
	char	*input;
	int		ret;
	int		i;
	int		count;

	fd = 0;
	ret = 1;
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		perror(file);
		return (-1);
	}
	input = NULL;
	count = 0;
	while (ret == 1)
	{
		i = -1;
		if ((ret = get_next_line(fd, &input, '\n')) > 0)
			ret = ft_arg_checker(head, input, &count);
		ft_strdel(&input);
	}
	ft_lstrev(head);
	close(fd);
	return (ret == -1 ? ret : count);
}
