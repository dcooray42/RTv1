/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:36:15 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:21:13 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	object_type(char *line, t_obj *obj, t_env **e)
{
	if (obj->status == 1)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (*line == '{')
		{
			line++;
			if (!obj->c)
				obj->c = init_pos(e);
			else
				syntax_error(e);
			obj->status = 2;
		}
		else
			syntax_error(e);
	}
	if (obj->status == 2)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (object_type_option(line, obj, e))
			return ;
		else
			syntax_error(e);
	}
}

int		object_type_option(char *line, t_obj *obj, t_env **e)
{
	if (!ft_memcmp(line, "Origin", 6))
	{
		line += 6;
		object_origin_coordinates(line, 1, e);
		return (1);
	}
	else if (!ft_memcmp(line, "Rotation_xyz", 12))
	{
		if (!ft_strcmp(obj->name, "Sphere"))
			syntax_error(e);
		line += 12;
		object_rotation(line, 1, e);
		return (1);
	}
	else if (!ft_memcmp(line, obj->name, ft_strlen(obj->name)))
	{
		object_type_option_ter(line, obj, e);
		return (1);
	}
	return (object_type_option_bis(line, obj));
}

void	object_origin_coordinates(char *line, int i, t_env **e)
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
	object_origin_coordinates_bis(line, i, j, e);
}

void	object_origin_coordinates_bis(char *line, int i, int j, t_env **e)
{
	t_obj	*obj;

	obj = (t_obj *)(*e)->list->content;
	if (i == 1)
	{
		obj->c->ori->x = ft_atoif(line);
		line += j;
		object_origin_coordinates(line, 2, e);
		return ;
	}
	if (i == 2)
	{
		obj->c->ori->y = ft_atoif(line);
		line += j;
		object_origin_coordinates(line, 3, e);
		return ;
	}
	if (i == 3)
	{
		obj->c->ori->z = ft_atoif(line);
		line += j;
	}
	object_ori_rot_final(line, e);
}

void	object_ori_rot_final(char *line, t_env **e)
{
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line != '}')
		syntax_error(e);
}
