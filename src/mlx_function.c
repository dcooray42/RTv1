/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:32:01 by dcooray           #+#    #+#             */
/*   Updated: 2017/06/09 00:46:56 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	mlx_put_pixel_to_image(t_win *win, int x, int y, t_inter *inter)
{
	int		i;

	i = (x * win->bpp / 8) + y * win->sizeline;
	win->data[i] = inter->clr->b;
	win->data[i + 1] = inter->clr->g;
	win->data[i + 2] = inter->clr->r;
}
