/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_visu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:20:10 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 15:33:50 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static int			ft_lst_to_tab(t_visu *visu, t_list *instructions)
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

static void			ft_init_anim(t_image *img)
{
	int i;
	int j;

	i = -1;
	while (++i < 125 && (j = -1))
		while (++j < 50)
			ft_put_pixel_img(img, i, j, 0xFF0000);
}

void				ft_create_backup(t_visu *visu)
{
	t_list		*list;

	list = visu->stack_a;
	visu->backup_list = NULL;
	while (list)
	{
		ft_add_to_list(&visu->backup_list, list->content,
														sizeof(list->content));
		list = list->next;
	}
	ft_lstrev(&visu->backup_list);
}

int					ft_set_visu_values(t_visu *visu, t_list *instructions)
{
	if (ft_lst_to_tab(visu, instructions))
		return (ft_free_visu(visu));
	visu->item_max_height = HEIGHT / visu->stack_size;
	visu->min_value = ft_get_min_value(visu->stack_a);
	visu->max_value = ft_get_max_value(visu->stack_a);
	visu->range = visu->max_value - visu->min_value;
	visu->item_max_width = visu->range;
	ft_init_colors(visu);
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
		ft_parse_args(ac, av, &visu->stack_a, &visu->flags)) == -1)
		return (ft_free_visu(visu));
	instructions = NULL;
	if (ft_read_instructions(&instructions, NULL))
		return (ft_free_visu(visu));
	if (ft_set_visu_values(visu, instructions) || !(visu->mlx_ptr = mlx_init()))
		return (ft_free_visu(visu));
	visu->win_ptr = mlx_new_window(visu->mlx_ptr, WIDTH, HEIGHT, "push_swap");
	if (!visu->win_ptr)
		return (ft_free_visu(visu));
	ft_create_image(&visu->img, WIDTH, HEIGHT, visu);
	ft_create_image(&visu->anim, 125, 50, visu);
	ft_init_anim(&visu->anim);
	mlx_mouse_hook(visu->win_ptr, &ft_mouse_event, visu);
	mlx_hook(visu->win_ptr, 2, 1L << 0, &ft_key_event, visu);
	mlx_loop_hook(visu->mlx_ptr, &ft_refresh, visu);
	mlx_hook(visu->win_ptr, 17, 1L << 17, &ft_close_event, visu);
	return (0);
}
