/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:32:56 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/26 21:52:26 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	delete_env(t_env **e)
{
	if (*e)
	{
		if ((*e)->name)
			ft_strdel(&(*e)->name);
		if ((*e)->win)
			delete_win((*e), (*e)->win);
		if ((*e)->cam)
		{
			if ((*e)->cam->ori)
				ft_memdel((void **)&(*e)->cam->ori);
			ft_memdel((void **)&(*e)->cam);
		}
		if ((*e)->list)
			ft_lstdel(&(*e)->list, &delete_obj);
		if ((*e)->light)
			ft_lstdel(&(*e)->light, &delete_light);
		if ((*e)->scene)
			delete_scene((*e)->scene);
		if ((*e)->tmp)
			delete_tmp((*e)->tmp);
		ft_memdel((void **)e);
	}
}

void	delete_scene(t_scene *scene)
{
	if (scene->lookatpoint)
		ft_memdel((void **)&scene->lookatpoint);
	if (scene->viewdirection)
		ft_memdel((void **)&scene->viewdirection);
	if (scene->u)
		ft_memdel((void **)&scene->u);
	if (scene->up)
		ft_memdel((void **)&scene->up);
	if (scene->v)
		ft_memdel((void **)&scene->v);
	if (scene->viewplaneupleftpoint)
		ft_memdel((void **)&scene->viewplaneupleftpoint);
	if (scene->viewplanepoint)
		ft_memdel((void **)&scene->viewplanepoint);
	if (scene->ray)
		ft_memdel((void **)&scene->ray);
	ft_memdel((void **)&scene);
}

void	delete_win(t_env *e, t_win *win)
{
	if (win->img)
		mlx_destroy_image(e->mlx, win->img);
	if (win->win)
		mlx_destroy_window(e->mlx, win->win);
	if (win->win_opt)
		mlx_destroy_window(e->mlx, win->win_opt);
	ft_memdel((void **)&win);
}

void	delete_obj(void *obj, size_t n)
{
	t_obj	*tmp;

	(void)n;
	tmp = (t_obj *)obj;
	if (tmp->name)
		ft_strdel(&tmp->name);
	if (tmp->clr)
		ft_memdel((void **)&tmp->clr);
	if (tmp->c)
	{
		if (tmp->c->ori)
			ft_memdel((void **)&tmp->c->ori);
		ft_memdel((void **)&tmp->c);
	}
	if (tmp->o_axis)
		ft_memdel((void **)&tmp->o_axis);
	if (tmp->abc)
		ft_memdel((void **)&tmp->abc);
	if (tmp->origintoobj)
		ft_memdel((void **)&tmp->origintoobj);
	ft_memdel((void **)&tmp);
}

void	delete_inter(void *inter, size_t n)
{
	t_inter	*tmp;

	(void)n;
	tmp = (t_inter *)inter;
	if (tmp->clr)
		ft_memdel((void **)&tmp->clr);
	if (tmp->point)
		ft_memdel((void **)&tmp->point);
	if (tmp->norm)
		ft_memdel((void **)&tmp->norm);
	ft_memdel((void **)&tmp);
}
