/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:17:54 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/13 16:23:40 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_tab(int *tab, int size)
{
	int swap;
	int i;
	int temp;

	swap = 1;
	while (swap)
	{
		swap = 0;
		i = 0;
		while (++i < size)
		{
			if (tab[i - 1] > tab[i])
			{
				temp = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = temp;
				swap = 1;
			}
		}
	}
}
