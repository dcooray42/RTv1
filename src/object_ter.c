/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_ter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:34:03 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:21:56 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	object_rotation(char *line, int i, t_env **e)
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
	object_rotation_bis(line, i, j, e);
}

void	object_rotation_bis(char *line, int i, int j, t_env **e)
{
	t_obj	*obj;

	obj = (t_obj *)(*e)->list->content;
	if (i == 1)
	{
		obj->c->rot_x = (ft_atoif(line) * M_PI) / 180;
		line += j;
		object_rotation(line, 2, e);
		return ;
	}
	if (i == 2)
	{
		obj->c->rot_y = (ft_atoif(line) * M_PI) / 180;
		line += j;
		object_rotation(line, 3, e);
		return ;
	}
	if (i == 3)
	{
		obj->c->rot_z = (ft_atoif(line) * M_PI) / 180;
		line += j;
	}
	object_ori_rot_final(line, e);
}

int		object_option_bis(char *line, t_env **e)
{
	if (!ft_memcmp(line, "Color", 5))
	{
		line += 5;
		object_color(line, 1, e);
		return (1);
	}
	else if (*line == '}')
	{
		(*e)->status = 1;
		return (1);
	}
	else if (*line == '\0')
		return (1);
	else
		return (0);
}

int		object_type_option_bis(char *line, t_obj *obj)
{
	if (*line == '}')
	{
		obj->status = 1;
		return (1);
	}
	else if (*line == '\0')
		return (1);
	else
		return (0);
}
