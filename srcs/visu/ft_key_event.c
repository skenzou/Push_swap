/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:49:35 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 14:15:28 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static const t_instruction		*get_oposite_instructions(void)
{
	static const t_instruction tab[NB_INSTRUCTIONS] = {
		{"rra", STACK_A, &ft_rotate},
		{"rrb", STACK_B, &ft_rotate},
		{"rrr", BOTH, &ft_rotate},
		{"sa", STACK_A, &ft_swap},
		{"sb", STACK_B, &ft_swap},
		{"ss", BOTH, &ft_swap},
		{"pa", STACK_B, &ft_push},
		{"pb", STACK_A, &ft_push},
		{"ra", STACK_A, &ft_reverse_rotate},
		{"rb", STACK_B, &ft_reverse_rotate},
		{"rr", BOTH, &ft_reverse_rotate},
	};

	return (tab);
}

static void						ft_go_back(t_visu *visu)
{
	int						i;
	const t_instruction		*instructions;

	if (visu->curr_instruction == 0)
		return ;
	i = -1;
	instructions = get_oposite_instructions();
	visu->curr_instruction--;
	while (++i < NB_INSTRUCTIONS)
		if (ft_strequ(visu->instructions[visu->curr_instruction]->op,
															instructions[i].op))
		{
			ft_execute_instruction((t_instruction *)&instructions[i],
												&visu->stack_a, &visu->stack_b);
			return ;
		}
}

static void						ft_reset(t_visu *visu)
{
	ft_destroy_lists(visu->stack_a, visu->stack_b, NULL);
	visu->stack_a = visu->backup_list;
	visu->stack_b = NULL;
	visu->curr_instruction = 0;
	ft_create_backup(visu);
}

int								ft_key_event(int keycode, t_visu *visu)
{
	if (keycode == ESCAPE)
	{
		ft_free_visu(visu);
		exit(0);
	}
	if (keycode == SPACE)
		visu->pause = !visu->pause;
	if (keycode == TAB)
		visu->colormode = !visu->colormode;
	if (keycode == RKEY)
	{
		ft_reset(visu);
		visu->pause = 1;
	}
	if (keycode == RIGHTARROW &&
				visu->curr_instruction < (size_t)visu->instructions_size)
	{
		ft_execute_instruction(visu->instructions[visu->curr_instruction],
		&visu->stack_a, &visu->stack_b);
		visu->curr_instruction++;
	}
	if (keycode == LEFTARROW && visu->curr_instruction > 0)
		ft_go_back(visu);
	return (1);
}
