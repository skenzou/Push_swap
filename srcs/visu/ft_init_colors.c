/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:03:34 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 14:18:51 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int					ft_init_color_table(t_visu *visu)
{
	int		i;
	int		rgb;
	int		color[3];

	if (!(visu->color_table =
							(int *)ft_memalloc(sizeof(int) * visu->stack_size)))
		return (-1);
	i = -1;
	color[0] = 255;
	color[1] = 0;
	color[2] = 0;
	while (++i < visu->stack_size)
	{
		(color[1] == 0 && color[0] == 255) && (color[2] += 3);
		(color[1] == 255 && color[0] == 0) && (color[2] -= 3);
		(color[1] == 0 && color[2] == 255) && (color[0] -= 3);
		(color[1] == 255 && color[2] == 0) && (color[0] += 3);
		(color[0] == 0 && color[2] == 255) && (color[1] += 3);
		(color[0] == 255 && color[2] == 0) && (color[1] -= 3);
		rgb = (color[0] << 16) + (color[1] << 8) + color[2];
		visu->color_table[i] = rgb;
	}
	return (0);
}

static int			ft_count_smaller(t_list *list, int value)
{
	int count;
	int content;

	count = 0;
	while (list)
	{
		ft_memcpy((void *)&content, list->content, sizeof(int));
		if (content < value)
			count++;
		list = list->next;
	}
	return (count);
}

static int			ft_remake_list(t_visu *visu)
{
	int		i;
	int		value;
	t_list	*list;
	t_item	*item;

	i = 0;
	list = visu->stack_a;
	while (list)
	{
		value = *((int *)list->content);
		if (!(item = (t_item *)ft_memalloc(sizeof(t_item))))
			return (-1);
		item->color = visu->color_table[ft_count_smaller(visu->stack_a, value)];
		item->value = value;
		free(list->content);
		list->content = (void *)item;
		list = list->next;
		i++;
	}
	return (0);
}

void				ft_init_colors(t_visu *visu)
{
	if (ft_init_color_table(visu) == -1 || ft_remake_list(visu) == -1)
	{
		ft_free_visu(visu);
		exit(1);
	}
	free(visu->color_table);
	visu->color_table = NULL;
}
