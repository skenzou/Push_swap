/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:39:46 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 13:40:24 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			ft_refresh(t_visu *visu)
{
	visu->sleep--;
	if (visu->sleep > 0)
		return (1);
	if (visu->curr_instruction == visu->instructions_size)
		visu->pause = 1;
	if (visu->curr_instruction < visu->instructions_size && !visu->pause)
	{
		ft_execute_instruction(visu->instructions[visu->curr_instruction],
		&visu->stack_a, &visu->stack_b);
		visu->curr_instruction++;
	}
	mlx_destroy_image(visu->mlx_ptr, visu->img.ptr);
	ft_create_image(&visu->img, WIDTH, HEIGHT, visu);
	ft_draw(visu);
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->img.ptr, 0, 0);
	ft_put_infos(visu);
	return (1);
}
