/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 09:35:07 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/19 17:46:47 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_ray(t_scene *scene, t_env *e)
{
	t_vect	*tmp1;
	t_vect	*tmp2;

	tmp1 = create_vect(e);
	tmp2 = create_vect(e);
	mult_vect_real(tmp1, scene->u, e->x * scene->xincvect);
	mult_vect_real(tmp2, scene->v, e->y * scene->yincvect);
	add_vect(scene->viewplanepoint, scene->viewplaneupleftpoint, tmp1);
	minus_vect(scene->viewplanepoint, scene->viewplanepoint, tmp2);
	minus_vect(scene->ray, scene->viewplanepoint, e->cam->ori);
	normalize(scene->ray);
	init_inter(e);
	ft_memdel((void **)&tmp1);
	ft_memdel((void **)&tmp2);
}

void	init_inter(t_env *e)
{
	t_inter	*inter;
	t_list	*tmp;

	if (!(inter = (t_inter *)ft_memalloc(sizeof(t_inter))))
		malloc_error(&e);
	inter->clr = create_color(e);
	inter->t = 0.0;
	inter->x = e->x;
	inter->y = e->y;
	inter->point = create_vect(e);
	inter->norm = create_vect(e);
	if (!(tmp = ft_lstnew(inter, sizeof(t_inter))))
		malloc_error(&e);
	ft_lstadd(&e->inter, tmp);
	ft_memdel((void **)&inter);
}

t_tmp	*init_tmp(t_env *e)
{
	t_tmp	*tmp;

	if (!(tmp = (t_tmp *)ft_memalloc(sizeof(t_tmp))))
		malloc_error(&e);
	tmp->t1 = 0.0;
	tmp->t2 = 0.0;
	tmp->m1 = 0.0;
	tmp->det = 0.0;
	tmp->tmp = 0.0;
	tmp->th = 0.0;
	tmp->length = 0.0;
	tmp->ombre = 0.0;
	tmp->tmp_vect = create_vect(e);
	tmp->tmp_vect_bis = create_vect(e);
	tmp->rfl_ray = create_vect(e);
	tmp->diffuse = create_color(e);
	tmp->phong = create_color(e);
	tmp->ambient = create_color(e);
	tmp->clr = create_color(e);
	tmp->light_clr = create_color(e);
	tmp->inter_clr = create_color(e);
	return (tmp);
}

t_color	*trace(t_vect *ori, t_vect *dir, t_inter *inter, t_env *e)
{
	t_color	*clr;

	clr = create_color(e);
	if (get_first_inter(inter, ori, dir, e))
	{
		inter->t = 0;
		ft_memdel((void **)&clr);
		return (shade(dir, inter, e));
	}
	return (clr);
}
