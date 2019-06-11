/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:14:21 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/11 11:35:04 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "visu.h"

int		main(int ac, char **av)
{
	t_visu		v;

	if (ft_init_visu(&v, ac, av) == -1)
		return (-1);
	mlx_loop(v.mlx_ptr);
}
