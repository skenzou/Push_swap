/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:33:38 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 15:02:44 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		ft_draw_item(t_visu *visu, int y_offset, int x_offset,
																t_item *item)
{
	int		item_w;
	int		i;
	int		j;
	int		color;

	if (visu->min_value < 0)
		item_w = ((float)(item->value - (visu->min_value - 1)) /
			(visu->max_value - (visu->min_value - 1))) * ITEM_WIDTH + x_offset;
	else
		item_w = ((float)item->value / visu->max_value) * ITEM_WIDTH + x_offset;
	if (visu->colormode == CLERP)
		color = ft_get_color(0x1E90FF, 0xDC143C, ft_percent(visu->min_value,
											visu->max_value, item->value));
	else
		color = item->color;
	i = -1 + x_offset;
	while (++i < item_w && (j = -1))
		while (++j < visu->item_max_height)
			if (x_offset == 0)
				ft_put_pixel_img(&visu->img, ITEM_WIDTH - i,
														j + y_offset, color);
			else
				ft_put_pixel_img(&visu->img, i, j + y_offset, color);
}

static void		ft_draw_middle(t_visu *visu)
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
		i = ITEM_WIDTH + 2;
		color = ft_get_color(0, 0x001942, ft_percent(0, HEIGHT, HEIGHT - j));
		while (++i < 1057)
			ft_put_pixel_img(&visu->img, i, j, color);
	}
}

static void		ft_print_buttons(t_visu *visu)
{
	int i;
	int j;
	int buttons;
	int end_i;
	int end_j;

	buttons = -1;
	end_i = 160 + ITEM_WIDTH;
	j = 350;
	while (++buttons < 5 && (i = ITEM_WIDTH + 35))
	{
		while (++i < end_i)
		{
			ft_put_pixel_img(&visu->img, i, j, 0xFFFFFF);
			ft_put_pixel_img(&visu->img, i, j + 50, 0xFFFFFF);
		}
		end_j = j + 50;
		i = ITEM_WIDTH + 35;
		while (j < end_j)
		{
			ft_put_pixel_img(&visu->img, i, j, 0xFFFFFF);
			ft_put_pixel_img(&visu->img, end_i, j, 0xFFFFFF);
			j++;
		}
	}
}

void			ft_draw(t_visu *visu)
{
	int		offset;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = visu->stack_a;
	stack_b = visu->stack_b;
	offset = 0;
	ft_draw_middle(visu);
	ft_print_buttons(visu);
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_draw_item(visu, offset, 0, (t_item *)stack_a->content);
			stack_a = stack_a->next;
		}
		if (stack_b)
		{
			ft_draw_item(visu, offset, ITEM_WIDTH + MIDDLE,
													(t_item *)stack_b->content);
			stack_b = stack_b->next;
		}
		offset += visu->item_max_height;
	}
}
