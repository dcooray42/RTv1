/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:27:17 by dcooray           #+#    #+#             */
/*   Updated: 2017/06/27 03:37:44 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color	*create_color(t_env *e)
{
	t_color	*clr;

	if (!(clr = (t_color *)ft_memalloc(sizeof(t_color))))
		malloc_error(&e);
	clr->r = 0.0;
	clr->g = 0.0;
	clr->b = 0.0;
	return (clr);
}

void	reinit_color(t_color *clr)
{
	clr->r = 0.0;
	clr->g = 0.0;
	clr->b = 0.0;
}

void	add_color(t_color *clr, t_color *tmp)
{
	clr->r += tmp->r;
	clr->g += tmp->g;
	clr->b += tmp->b;
}

void	mult_color(t_color *clr, t_color *tmp1, t_color *tmp2)
{
	clr->r = tmp1->r * tmp2->r;
	clr->g = tmp1->g * tmp2->g;
	clr->b = tmp1->b * tmp2->b;
}

void	mult_color_real(t_color *tmp, t_color *clr, double n)
{
	tmp->r = clr->r * n;
	tmp->g = clr->g * n;
	tmp->b = clr->b * n;
}
