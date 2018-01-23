/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:30:37 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/11 04:22:36 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt(t_env *e)
{
	t_win	*win;

	win = e->win;
	if (!win->tmp)
	{
		if (!(e->mlx = mlx_init()))
			malloc_error(&e);
		if (!(win->win = mlx_new_window(e->mlx, win->width, win->height,
						e->name)))
			malloc_error(&e);
		if (!(win->win_opt = mlx_new_window(e->mlx, 500, 500, "Setup")))
			malloc_error(&e);
		if (!(win->img = mlx_new_image(e->mlx, win->width, win->height)))
			malloc_error(&e);
		if (!(win->data = mlx_get_data_addr(win->img, &win->bpp, &win->sizeline,
					&win->endian)))
			malloc_error(&e);
		win->tmp = 1;
	}
	rt_bis(win, e);
}

t_scene	*init_scene(t_env *e)
{
	t_scene	*scene;

	if ((scene = (t_scene *)ft_memalloc(sizeof(t_scene))) == NULL)
		syntax_error(&e);
	scene->lookatpoint = create_vect(e);
	scene->viewdirection = create_vect(e);
	scene->u = create_vect(e);
	scene->up = create_vect(e);
	scene->v = create_vect(e);
	scene->aspectratio = 0.0;
	scene->viewplanewidth = 0.0;
	scene->viewplaneheight = 0.0;
	scene->viewplaneupleftpoint = create_vect(e);
	scene->xincvect = 0.0;
	scene->yincvect = 0.0;
	scene->viewplanepoint = create_vect(e);
	scene->ray = create_vect(e);
	return (scene);
}

void	set_camera_scene(t_scene *scene, t_pos *cam, t_win *win, t_env *e)
{
	init_vect(scene->lookatpoint, 0.0, 0.0, 0.0);
	minus_vect(scene->viewdirection, scene->lookatpoint, e->cam->ori);
	normalize(scene->viewdirection);
	if (!cam->ori->x && !cam->ori->z)
		init_vect(scene->up, -1.0, 0.0, 0.0);
	else
		init_vect(scene->up, 0.0, 1.0, 0.0);
	cross_product(scene->u, scene->viewdirection, scene->up);
	cross_product(scene->v, scene->u, scene->viewdirection);
	scene->viewplanewidth = tan(cam->fov / 2);
	scene->aspectratio = (double)win->height / (double)win->width;
	scene->viewplaneheight = scene->aspectratio * scene->viewplanewidth;
	set_camera_scene_bis(scene, e);
}

void	set_camera_scene_bis(t_scene *scene, t_env *e)
{
	t_vect	*tmp1;
	t_vect	*tmp2;

	tmp1 = create_vect(e);
	tmp2 = create_vect(e);
	mult_vect_real(tmp1, scene->v, scene->viewplaneheight / 2.0);
	mult_vect_real(tmp2, scene->u, scene->viewplanewidth / 2.0);
	add_vect(scene->viewplaneupleftpoint, e->cam->ori, scene->viewdirection);
	add_vect(scene->viewplaneupleftpoint, scene->viewplaneupleftpoint, tmp1);
	minus_vect(scene->viewplaneupleftpoint, scene->viewplaneupleftpoint, tmp2);
	scene->xincvect = scene->viewplanewidth / (double)e->win->width;
	scene->yincvect = scene->viewplaneheight / (double)e->win->height;
	rotation(e);
	ft_memdel((void **)&tmp1);
	ft_memdel((void **)&tmp2);
}

void	render(t_env *e)
{
	t_inter	*inter;
	t_list	*list2;

	if (!e->scene)
		e->scene = init_scene(e);
	set_camera_scene(e->scene, e->cam, e->win, e);
	e->y = 0;
	while (e->y < e->win->height)
	{
		e->x = 0;
		while (e->x < e->win->width)
		{
			render_bis(e);
			e->x++;
		}
		e->y++;
	}
	list2 = e->inter;
	while (list2)
	{
		inter = (t_inter *)list2->content;
		mlx_put_pixel_to_image(e->win, inter->x, inter->y, inter);
		list2 = list2->next;
	}
	ft_lstdel(&e->inter, &delete_inter);
}
