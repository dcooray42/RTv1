/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculus_ter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:31:34 by dcooray           #+#    #+#             */
/*   Updated: 2017/06/27 02:32:06 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	vect_length(t_vect *t1)
{
	double	t;

	t = sqrt(pow(t1->x, 2) + pow(t1->y, 2) + pow(t1->z, 2));
	return (t);
}

void	reflected_ray(t_tmp *tmp, t_vect *ray, t_vect *norm)
{
	double	dot;

	tmp->rfl_ray->x = 0.0;
	tmp->rfl_ray->y = 0.0;
	tmp->rfl_ray->z = 0.0;
	dot = -dot_product(norm, ray);
	mult_vect_real(tmp->rfl_ray, norm, 2 * dot);
	add_vect(tmp->rfl_ray, tmp->rfl_ray, ray);
	normalize(tmp->rfl_ray);
}

void	cpy_vect(t_vect *t1, t_vect *t2)
{
	t1->x = t2->x;
	t1->y = t2->y;
	t1->z = t2->z;
}
