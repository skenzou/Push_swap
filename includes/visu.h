/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:12:49 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/14 23:47:53 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# include "mlx.h"
# include "push_swap.h"
# define ESCAPE			53
# define SPACE			49
# define RIGHTARROW		124
# define LEFTARROW		123
# define WIDTH			1920
# define ITEM_WIDTH		860
# define MIDDLE			200
# define HEIGHT			1080
# define WHITE			0xFFFFFF
# define RAINBOW		1
# define CLERP			0
# define RKEY			15
# define TAB			48

typedef struct		s_image
{
	void				*ptr;
	char				*data;
	int					bpp;
	int					sizeline;
	int					endian;
	int					height;
	int					width;
	int					test;
}					t_image;

typedef struct		s_visu
{
	t_image				img;
	void				*mlx_ptr;
	void				*win_ptr;
	int					item_max_width;
	int					item_max_height;
	int					stack_size;
	t_list				*stack_a;
	t_list				*stack_b;
	t_list				*backup_list;
	int					*color_table;
	t_instruction		**instructions;
	size_t				curr_instruction;
	size_t				instructions_size;
	int					min_value;
	int					max_value;
	int					range;
	char				flags;
	char				pause;
	char				colormode;
}					t_visu;

typedef struct		s_item
{
	int					value;
	int					color;
}					t_item;


/*
** INIT_VISU.C
*/
int				ft_init_visu(t_visu *visu, int ac, char **av);
int				ft_free_visu(t_visu *visu);
void 			ft_create_backup(t_visu *visu);
int				set_values(t_visu *visu, t_list *instructions);
void 			ft_create_backup(t_visu *visu);
/*
**	EVENTS.C
*/
int				close_click(t_visu *visu);
int				refresh(t_visu *w);
int				key_event(int keycode, t_visu *visu);
int				mouse_event(int b, int x, int y, t_visu *visu);
/*
** IMAGE.C
*/
int				ft_put_pixel_img(t_image *img, int x, int y, int color);
void			ft_create_image(t_visu *visu, int width, int height);
/*
** FT_DRAW.C
*/
void			ft_draw(t_visu *visu);
void			ft_put_infos(t_visu *visu);
/*
** FT_GENERATE_NUMBERS.C
*/
void			ft_generate_numbers(int size, t_visu *visu);

#endif
