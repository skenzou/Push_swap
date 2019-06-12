/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 09:33:38 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/12 05:08:20 by Mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "push_swap.h"

void		ft_draw_item(t_visu *visu, int value, int y_offset, int x_offset, int color)
{
	int		item_w;
	int		i;
	int		j;

	item_w = (HALF_WIDTH * value) / visu->item_max_width + x_offset;
	i = -1 + x_offset;
	while(++i < item_w && (j = -1))
		while (++j < visu->item_max_height)
			ft_put_pixel_img(&visu->img, i, j + y_offset, color);
			// ft_put_pixel_img(&visu->img, i, j + y_offset, ft_get_color
			// (0xFF0000, 0x0F0FAF,
			// 			ft_percent(visu->min_value, visu->max_value, value)));

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
					offset_b, WIDTH / 2, ((t_item *)stack_b->content)->color);
			offset_b += visu->item_max_height;
			stack_b = stack_b->next;
		}
	}
}
