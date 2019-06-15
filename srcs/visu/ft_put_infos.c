/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:25:16 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 14:33:00 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		ft_print_next_instructions(t_visu *visu)
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

static void		ft_put_labels(t_visu *visu)
{
	if (visu->pause)
		mlx_string_put(visu->mlx_ptr, visu->win_ptr,
		ITEM_WIDTH + 65, 10, WHITE, "PAUSED");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 5, 50, WHITE,
	"A                 B");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 5, 100, WHITE,
	"Size:");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 5, 140, WHITE,
	"Moves:");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 5, 180, WHITE,
	"Current:");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 80, 360, WHITE,
	"1000");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 82, 410, WHITE,
	"500");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 83, 460, WHITE,
	"100");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 86, 510, WHITE,
	"50");
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 86, 560, WHITE,
	"10");
}

void			ft_put_infos(t_visu *visu)
{
	char *size;
	char *instructions;
	char *current;

	current = ft_itoa(visu->curr_instruction);
	size = ft_itoa(visu->stack_size);
	instructions = ft_itoa(visu->instructions_size);
	if (!current || !size || !instructions)
	{
		ft_free_visu(visu);
		exit(1);
	}
	ft_put_labels(visu);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 60, 100, WHITE,
	size);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 70, 140, WHITE,
	instructions);
	mlx_string_put(visu->mlx_ptr, visu->win_ptr, ITEM_WIDTH + 90, 180, WHITE,
	current);
	ft_print_next_instructions(visu);
	free(current);
	free(size);
	free(instructions);
}
