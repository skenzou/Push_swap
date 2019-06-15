/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midrissi <midrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 08:54:33 by midrissi          #+#    #+#             */
/*   Updated: 2019/06/15 14:15:57 by midrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			ft_put_pixel_img(t_image *img, int x, int y, int color)
{
	int offset;

	offset = ((x + y * img->width) * img->bpp);
	if (x < img->width && x >= 0 && y < img->height && y >= 0)
	{
		img->data[offset] = color & 0xFF;
		img->data[offset + 1] = (color >> 8) & 0xFF;
		img->data[offset + 2] = (color >> 16) & 0xFF;
		img->data[offset + 3] = (color >> 24) & 0xFF;
	}
	return (1);
}

void		ft_create_image(t_image *img, int width, int height, t_visu *visu)
{
	img->ptr = mlx_new_image(visu->mlx_ptr, width, height);
	img->width = width;
	img->height = height;
	if (!(img->ptr))
	{
		ft_free_visu(visu);
		exit(1);
	}
	img->data = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->sizeline, &img->endian);
	img->bpp /= 8;
}
