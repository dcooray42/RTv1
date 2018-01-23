/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 05:51:56 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 18:47:31 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	*shade(t_vect *dir, t_inter *inter, t_env *e)
{
	t_color	*radiance;
	t_list	*list;

	radiance = create_color(e);
	list = e->light;
	mod_color(e->tmp->inter_clr, inter->clr);
	if (!list)
		add_color(radiance, e->tmp->inter_clr);
	if (list)
	{
		add_color(radiance, e->tmp->inter_clr);
		mult_color_real(radiance, radiance, 0.1);
		shade_bis(radiance, dir, inter, e);
	}
	return (radiance);
}

void	shade_bis(t_color *radiance, t_vect *dir, t_inter *inter, t_env *e)
{
	t_list	*list;
	t_light	*light;
	double	shade;
	t_color	*clr_tmp;

	list = e->light;
	while (list)
	{
		light = (t_light *)list->content;
		mod_color(e->tmp->light_clr, light->clr);
		minus_vect(light->dir, light->ori, inter->point);
		normalize(light->dir);
		if ((shade = dot_product(light->dir, inter->norm)) > 0)
		{
			shade_ter(light, inter, e);
			clr_tmp = phong(shade, dir, light, e);
			add_color(radiance, clr_tmp);
			ft_memdel((void **)&clr_tmp);
		}
		list = list->next;
	}
}

void	shade_ter(t_light *light, t_inter *inter, t_env *e)
{
	e->tmp->ombre = 1.0;
	mult_vect_real(e->tmp->tmp_vect, inter->norm, 10e-10);
	add_vect(e->tmp->tmp_vect, e->tmp->tmp_vect, inter->point);
	minus_vect(e->tmp->rfl_ray, light->ori, e->tmp->tmp_vect);
	e->tmp->length = vect_length(e->tmp->rfl_ray) + 10e-10;
	normalize(e->tmp->rfl_ray);
	if (intersection(e->tmp->tmp_vect, e->tmp->rfl_ray, e))
		e->tmp->ombre = 0.0;
}

t_color	*phong(double shade, t_vect *dir, t_light *light, t_env *e)
{
	t_color	*clr;
	t_inter	*inter;
	double	i;

	inter = (t_inter *)e->inter->content;
	clr = create_color(e);
	mult_color(e->tmp->diffuse, e->tmp->inter_clr, e->tmp->light_clr);
	mult_color_real(e->tmp->diffuse, e->tmp->diffuse, shade * e->tmp->ombre);
	reflected_ray(e->tmp, light->dir, inter->norm);
	reinit_color(e->tmp->phong);
	if ((i = dot_product(e->tmp->rfl_ray, dir)) > 0)
	{
		add_color(e->tmp->phong, e->tmp->light_clr);
		mult_color_real(e->tmp->phong, e->tmp->phong,
				pow(i, 180) * e->tmp->ombre);
	}
	add_color(clr, e->tmp->diffuse);
	add_color(clr, e->tmp->phong);
	return (clr);
}
