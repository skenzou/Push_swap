/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:33:38 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/13 20:19:05 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "push_swap.h"

void		ft_draw_item(t_visu *visu, int value, int y_offset, int x_offset,
																	int color)
{
	int		item_w;
	int		i;
	int		j;

	if (visu->min_value < 0)
		item_w = ((float)(value - (visu->min_value - 1)) /
			(visu->max_value - (visu->min_value - 1))) * ITEM_WIDTH + x_offset;
	else
		item_w = ((float)value / visu->max_value) * ITEM_WIDTH + x_offset;
	if (visu->colormode == CLERP)
		color = ft_get_color(0x1E90FF, 0xDC143C, ft_percent(visu->min_value,
											visu->max_value, value));
	i = -1 + x_offset;
	while(++i < item_w && (j = -1))
		while (++j < visu->item_max_height)
			if (x_offset == 0)
				ft_put_pixel_img(&visu->img, ITEM_WIDTH - i, j + y_offset, color);
			else
				ft_put_pixel_img(&visu->img, i, j + y_offset, color);
}

void		ft_draw_middle(t_visu *visu)
{
	int i;
	int j;
	int color;

	j = -1;
	while (++j < HEIGHT)
	{

		ft_put_pixel_img(&visu->img, ITEM_WIDTH, j, WHITE);
		ft_put_pixel_img(&visu->img, ITEM_WIDTH + 1, j, WHITE);
		ft_put_pixel_img(&visu->img, ITEM_WIDTH + 2, j, WHITE);
		ft_put_pixel_img(&visu->img, 1057, j, WHITE);
		ft_put_pixel_img(&visu->img, 1057 + 1, j, WHITE);
		ft_put_pixel_img(&visu->img, 1057 + 2, j, WHITE);
		i = ITEM_WIDTH +2;
		color = ft_get_color(0, 0x001942, ft_percent(0, HEIGHT, HEIGHT - j));
		while (++i < 1057)
			ft_put_pixel_img(&visu->img, i, j, color);
	}
}

void		ft_print_next_instructions(t_visu *visu)
{
	int		i;
	int		j;
	int		offset;

	i = visu->curr_instruction;
	j = -1;
	offset = 0;
	while ((size_t)i < visu->instructions_size && ++j < 4)
	{
		mlx_string_put(visu->mlx_ptr, visu->win_ptr,
		ITEM_WIDTH + 85, 220 + offset, WHITE, visu->instructions[i++]->op);
		offset += 20;
	}
}

void		ft_put_infos(t_visu *visu)
{
	char *size;
	char *instructions;
	char *current;

	current = ft_itoa(visu->curr_instruction);
	size = ft_itoa(visu->stack_size);
	instructions = ft_itoa(visu->instructions_size);
	if (!current || ! size || !instructions)
	{
		ft_free_visu(visu);
		exit(1);
	}
	if (visu->pause)
		mlx_string_put(visu->mlx_ptr, visu->win_ptr,
		ITEM_WIDTH + 65, 10, WHITE, "PAUSED");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 5, 50, WHITE,
	"A                 B");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 5, 100, WHITE,
	"Size:");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 60, 100, WHITE,
	size);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr,  ITEM_WIDTH + 5, 140, WHITE,
	"Moves:");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr,  ITEM_WIDTH + 70, 140, WHITE,
	instructions);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 5, 180, WHITE,
	"Current:");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 90, 180, WHITE,
	current);
	ft_print_next_instructions(visu);
	free(current);
	free(size);
	free(instructions);
// 		 t_list *list;
// 	list = visu->stack_a;
// 	 int i = 0;
//
// 	while (list)
// 	{
// 		mlx_string_put(visu->mlx_ptr, visu->win_ptr, 10 , 1 + i, WHITE,
// 		ft_itoa(((t_item *)list->content)->value));
// 		i += 13;
// 		list = list->next;
// 	}
}

void		ft_draw(t_visu *visu)
{
	int		offset_a;
	int		offset_b;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = visu->stack_a;
	stack_b = visu->stack_b;
	offset_a = 0;
	offset_b = 0;
	ft_draw_middle(visu);
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_draw_item(visu, ((t_item *)stack_a->content)->value,
							offset_a, 0, ((t_item *)stack_a->content)->color);
			offset_a += visu->item_max_height;
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			ft_draw_item(visu, ((t_item *)stack_b->content)->value,
			offset_b, ITEM_WIDTH + MIDDLE, ((t_item *)stack_b->content)->color);
			offset_b += visu->item_max_height;
			stack_b = stack_b->next;
		}
	}

}
