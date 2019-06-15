/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:40:32 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 14:59:08 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			ft_free_visu(t_visu *visu)
{
	int i;

	if (visu->instructions)
	{
		i = -1;
		while ((size_t)++i < visu->instructions_size)
			free(visu->instructions[i]);
		free(visu->instructions);
	}
	free(visu->color_table);
	free(visu->mlx_ptr);
	free(visu->win_ptr);
	free(visu->img.ptr);
	free(visu->anim.ptr);
	ft_destroy_lists(visu->stack_a, visu->stack_b, visu->backup_list);
	return (-1);
}
