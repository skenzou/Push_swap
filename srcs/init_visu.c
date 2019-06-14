/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:20:10 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 01:16:03 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int					ft_free_visu(t_visu *visu)
{
	int i;

	if (visu->instructions)
	{
		i = -1;
		while((size_t)++i < visu->instructions_size)
			free(visu->instructions[i]);
		free(visu->instructions);
	}
	free(visu->mlx_ptr);
	free(visu->win_ptr);
	free(visu->img.ptr);
	destroy_lists(visu->stack_a, visu->stack_b, visu->backup_list);
	return (-1);
}

int					ft_lst_to_tab(t_visu *visu, t_list *instructions)
{
	int		i;
	t_list	*tmp;

	visu->instructions_size = ft_lstsize(instructions);
	if (!(visu->instructions = (t_instruction **)
			ft_memalloc(sizeof(t_instruction *) * visu->instructions_size)))
		return (-1);
	i = 0;
	while (instructions)
	{
		visu->instructions[i++] = (t_instruction *)instructions->content;
		tmp = instructions;
		instructions = instructions->next;
		free(tmp);
	}
	return (0);
}

int					ft_init_color_table(t_visu *visu)
{
	int		i;
	int		rgb;
	int		color[3];

	if (!(visu->color_table = (int *)ft_memalloc(sizeof(int) * visu->stack_size)))
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

int					ft_count_smaller(t_list *list, int value)
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

void 				ft_create_backup(t_visu *visu)
{
	t_list		*list;

	list = visu->stack_a;
	visu->backup_list = NULL;
	while (list)
	{
		add_to_list(&visu->backup_list, list->content, sizeof(list->content));
		list = list->next;
	}
	ft_lstrev(&visu->backup_list);
}

int					ft_init_colors(t_visu *visu)
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
int					set_values(t_visu *visu, t_list *instructions)
{
	if (ft_lst_to_tab(visu, instructions))
		return (ft_free_visu(visu));
	visu->item_max_height = HEIGHT / visu->stack_size;
	visu->min_value = ft_get_min_value(visu->stack_a);
	visu->max_value = ft_get_max_value(visu->stack_a);
	visu->range = visu->max_value - visu->min_value;
	visu->item_max_width = visu->range;
	if (ft_init_color_table(visu) == -1)
		return (ft_free_visu(visu));
	if (ft_init_colors(visu) == -1)
		return (ft_free_visu(visu));
	free(visu->color_table);
	ft_lstdestroy(&visu->backup_list);
	ft_create_backup(visu);
	return (0);
}

int					ft_init_visu(t_visu *visu, int ac, char **av)
{
	t_list		*instructions;

	ft_bzero((void *)visu, sizeof(t_visu));
	ft_bzero((void *)&visu->img, sizeof(t_image));
	if ((visu->stack_size =
		parse_args(ac, av, &visu->stack_a, &visu->flags)) == -1)
		return (ft_free_visu(visu));
	instructions = NULL;
	if (read_instructions(&instructions,
							(visu->flags & INSTRU_FROM_FILE) ? av[1] : NULL))
		return (ft_free_visu(visu));
	if (set_values(visu, instructions))
		return (-1);
	if (!(visu->mlx_ptr = mlx_init()))
		return (-1);
	visu->win_ptr = mlx_new_window(visu->mlx_ptr, WIDTH, HEIGHT, "push_swap");
	if (!visu->win_ptr)
		return (ft_free_visu(visu));
	ft_create_image(visu, WIDTH, HEIGHT);
	mlx_mouse_hook(visu->win_ptr, &mouse_event, visu);
	mlx_hook(visu->win_ptr, 2, 1L << 0, &key_event, visu);
	mlx_loop_hook(visu->mlx_ptr, &refresh, visu);
	mlx_hook(visu->win_ptr, 17, 1L << 17, &close_click, visu);
	return (0);
}
