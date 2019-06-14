/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 21:08:17 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 00:55:38 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

const char 	*const	*get_cmd(int size)
{
	static const char * const cmd_1000[] ={
	"/usr/bin/ruby",  "-e", "puts (-500..499).to_a.shuffle.join(' ')", NULL};
	static const char * const cmd_500[] ={
	"/usr/bin/ruby",  "-e", "puts (-250..249).to_a.shuffle.join(' ')", NULL};
	static const char * const cmd_100[] ={
	"/usr/bin/ruby",  "-e", "puts (-50..49).to_a.shuffle.join(' ')", NULL};
	static const char * const cmd_50[] ={
	"/usr/bin/ruby",  "-e", "puts (-25..24).to_a.shuffle.join(' ')", NULL};
	static const char * const cmd_10[] ={
	"/usr/bin/ruby",  "-e", "puts (-5..4).to_a.shuffle.join(' ')", NULL};

	if (size == 1000)
		return (cmd_1000);
	else if (size == 500)
		return (cmd_500);
	else if (size == 100)
		return (cmd_100);
	else if (size == 50)
		return (cmd_50);
	else
		return (cmd_10);

}

void		ft_clear_data(t_visu *visu)
{
	int i;

	if (visu->instructions)
	{
		i = -1;
		while((size_t)++i < visu->instructions_size)
			free(visu->instructions[i]);
		free(visu->instructions);
	}
	destroy_lists(visu->stack_a, visu->stack_b, visu->backup_list);
	visu->stack_a = NULL;
	visu->stack_b = NULL;
	visu->backup_list = NULL;
	visu->curr_instruction = 0;
}

void		ft_reload_visu(t_visu *visu)
{
	int			stdout;
	int			fd;
	t_list		*instructions;

	visu->stack_size = read_from_file(".values", &visu->stack_a);
	fd = open(".instructions", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (visu->stack_size == 1 || fd == -1 ||
		(stdout = dup(STDOUT_FILENO)) == -1 || dup2(fd, STDOUT_FILENO) == -1)
	{
		ft_free_visu(visu);
		exit(1);
	}
	ft_create_backup(visu);
	ft_launch_sort(visu->stack_size, &visu->stack_a, &visu->stack_b);
	ft_lstdestroy(&visu->stack_a);
	visu->stack_a = visu->backup_list;
	ft_create_backup(visu);
	close(fd);
	if (dup2(stdout, STDOUT_FILENO) == -1 ||
							read_instructions(&instructions, ".instructions"))
	{
		ft_free_visu(visu);
		exit(1);
	}
	set_values(visu, instructions);
}

void		ft_generate_numbers(int size, t_visu *visu)
{
	pid_t				pid;
	int					fd;
	const char * const	*cmd;

	cmd = get_cmd(size);
	fd = open(".values", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1 || (pid = fork()) == -1)
	{
		ft_free_visu(visu);
		exit(1);
	}
	if (pid == 0)
	{
		dup2(fd, STDOUT_FILENO);
		execve(cmd[0], (char * const *)cmd, NULL);
		exit(1);
	}
	if (pid > 0)
		wait(&pid);
	close(fd);
	ft_clear_data(visu);
	ft_reload_visu(visu);
}
