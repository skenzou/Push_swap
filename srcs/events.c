/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:35:21 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 03:15:30 by Mohamed          ###   ########.fr       */
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

void		ft_reset(t_visu *visu)
{
	destroy_lists(visu->stack_a, visu->stack_b, NULL);
	visu->stack_a = visu->backup_list;
	visu->stack_b = NULL;
	visu->curr_instruction = 0;
	ft_create_backup(visu);
}

int			mouse_event(int b, int x, int y, t_visu *visu)
{
	int start;
	(void)b;
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
		mlx_put_image_to_window(visu->mlx_ptr, visu->win_ptr,
										visu->anim.ptr, ITEM_WIDTH + 35, start);
		visu->pause = 1;
	}
	return (1);
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
	if (keycode == TAB)
		visu->colormode = !visu->colormode;
	if (keycode == RKEY)
	{
		ft_reset(visu);
		visu->pause = 1;
	}
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
