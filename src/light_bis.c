/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 20:55:34 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:27:31 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	light_color(char *line, int i, t_env **e)
{
	char	*str;
	int		j;

	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{')
		line++;
	else if (i == 1)
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	str = line;
	j = 0;
	while (!ft_isspace(*str) && *str != '}' && *str != '\0')
	{
		j++;
		str++;
	}
	light_color_bis(line, i, j, e);
}

void	light_color_bis(char *line, int i, int j, t_env **e)
{
	t_light	*light;

	light = (t_light *)(*e)->light->content;
	if (i == 1)
	{
		light->clr->r = (double)get_color(line, e);
		line += j;
		light_color(line, 2, e);
		return ;
	}
	if (i == 2)
	{
		light->clr->g = (double)get_color(line, e);
		line += j;
		light_color(line, 3, e);
		return ;
	}
	if (i == 3)
	{
		light->clr->b = (double)get_color(line, e);
		line += j;
	}
	object_ori_rot_final(line, e);
}
