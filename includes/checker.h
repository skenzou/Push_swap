/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 01:49:30 by midrissi          #+#    #+#             */
/*   Updated: 2019/05/31 12:22:58 by Mohamed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

int		read_instructions(t_list **head);
int		parse_args(int ac, char **av, t_list **head);
int		add_to_list(t_list **head, void *data, size_t size);
void	print_list(t_list *list, char number);

#endif
