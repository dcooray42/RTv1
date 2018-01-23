/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 22:27:42 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/19 17:47:01 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	delete_tmp(t_tmp *tmp)
{
	if (tmp->tmp_vect)
		ft_memdel((void **)&tmp->tmp_vect);
	if (tmp->tmp_vect_bis)
		ft_memdel((void **)&tmp->tmp_vect_bis);
	if (tmp->rfl_ray)
		ft_memdel((void **)&tmp->rfl_ray);
	if (tmp->diffuse)
		ft_memdel((void **)&tmp->diffuse);
	if (tmp->phong)
		ft_memdel((void **)&tmp->phong);
	if (tmp->ambient)
		ft_memdel((void **)&tmp->ambient);
	if (tmp->clr)
		ft_memdel((void **)&tmp->clr);
	if (tmp->light_clr)
		ft_memdel((void **)&tmp->light_clr);
	if (tmp->inter_clr)
		ft_memdel((void **)&tmp->inter_clr);
	ft_memdel((void **)&tmp);
}

void	delete_light(void *light, size_t n)
{
	t_light *tmp;

	(void)n;
	tmp = (t_light *)light;
	if (tmp->dir)
		ft_memdel((void **)&tmp->dir);
	if (tmp->ori)
		ft_memdel((void **)&tmp->ori);
	if (tmp->clr)
		ft_memdel((void **)&tmp->clr);
	ft_memdel((void **)&tmp);
}
