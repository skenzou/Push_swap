/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:49:20 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 13:51:11 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			ft_mouse_event(int b, int x, int y, t_visu *visu)
{
	int start;

	(void)b;
	start = 0;
	if (x >= 895 && x <= 1019)
	{
		visu->sleep = 5;
		if (y >= 350 && y < 400 && (start = 350))
			ft_generate_numbers(1000, visu);
		if (y >= 400 && y < 450 && (start = 400))
			ft_generate_numbers(500, visu);
		if (y >= 450 && y < 500 && (start = 450))
			ft_generate_numbers(100, visu);
		if (y >= 500 && y < 550 && (start = 500))
			ft_generate_numbers(50, visu);
		if (y >= 550 && y < 600 && (start = 550))
			ft_generate_numbers(10, visu);
		if (start)
		{
			mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr,
				visu->anim.ptr, ITEM_WIDTH + 35, start);
			visu->pause = 1;
		}
	}
	return (1);
}
