/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 02:28:58 by dcooray           #+#    #+#             */
/*   Updated: 2017/06/27 02:34:47 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	div_color_real(t_color *clr, double n)
{
	clr->r /= n;
	clr->g /= n;
	clr->b /= n;
}

void	mod_color(t_color *clr, t_color *tmp)
{
	clr->r = tmp->r / 255;
	clr->g = tmp->g / 255;
	clr->b = tmp->b / 255;
}

void	color_cpy(t_color *tmp, t_color *clr)
{
	tmp->r = clr->r;
	tmp->g = clr->g;
	tmp->b = clr->b;
}
