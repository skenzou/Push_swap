/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:35:21 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/12 12:49:09 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static const t_instruction	 *get_oposite_instructions()
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


static void		ft_execute_instruction(t_instruction *instruction,
								t_list **stack_a, t_list **stack_b)
{
	if (instruction->dest == STACK_A)
		instruction->function(stack_a, stack_b, NO_WRITE);
	else if (instruction->dest == STACK_B)
		instruction->function(stack_b, stack_a, NO_WRITE);
	else
	{
		instruction->function(stack_a, stack_b, NO_WRITE);
		instruction->function(stack_b, stack_a, NO_WRITE);
	}
}

int			refresh(t_visu *visu)
{
	if (visu->curr_instruction < visu->instructions_size && !visu->pause)
	{
		ft_execute_instruction(visu->instructions[visu->curr_instruction],
		&visu->stack_a, &visu->stack_b);
		visu->curr_instruction++;
	}
	mlx_destroy_image(visu->mlx_ptr, visu->img.ptr);
	ft_create_image(visu, WIDTH, HEIGHT);
	ft_draw(visu);
	mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr, visu->img.ptr, 0, 0);
	ft_put_infos(visu);
	return (1);
}

int				close_click(t_visu *v)
{
	ft_free_visu(v);
	exit(0);
	return (0);
}

static void		ft_go_back(t_visu *visu)
{
	int i;
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


int			key_event(int keycode, t_visu *visu)
{
	if (keycode == ESCAPE)
	{
		ft_free_visu(visu);
		exit(0);
	}
	if (keycode == SPACE)
		visu->pause = !visu->pause;
	if (keycode == RKEY)
		visu->colormode = !visu->colormode;
	if (keycode == RIGHTARROW &&
				visu->curr_instruction < (size_t)visu->instructions_size - 1)
	{
		ft_execute_instruction(visu->instructions[visu->curr_instruction],
		&visu->stack_a, &visu->stack_b);
		visu->curr_instruction++;
	}
	if (keycode == LEFTARROW && visu->curr_instruction > 0)
		ft_go_back(visu);
	return (1);
}
