/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_bis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:43:09 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/10 17:13:17 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	render_bis(t_env *e)
{
	t_color *clr;
	t_inter	*inter;

	get_ray(e->scene, e);
	inter = (t_inter *)e->inter->content;
	clr = trace(e->cam->ori, e->scene->ray, inter, e);
	color_cpy(inter->clr, clr);
	mult_color_real(inter->clr, inter->clr, 256);
	inter->clr->r = (inter->clr->r > 255) ? 255 : inter->clr->r;
	inter->clr->g = (inter->clr->g > 255) ? 255 : inter->clr->g;
	inter->clr->b = (inter->clr->b > 255) ? 255 : inter->clr->b;
	ft_memdel((void **)&clr);
}

void	rt_bis(t_win *win, t_env *e)
{
	render(e);
	main_menu_setup(e);
	mlx_put_image_to_window(e->mlx, e->win->win, e->win->img, 0, 0);
	mlx_key_hook(win->win, &key_hook_rt, e);
	mlx_key_hook(win->win_opt, &key_hook_setup, e);
	mlx_hook(win->win, 17, (1L << 17), &red_cross, e);
	mlx_loop(e->mlx);
}
