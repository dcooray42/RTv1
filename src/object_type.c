/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:35:10 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:23:14 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	object_type_option_ter(char *line, t_obj *obj, t_env **e)
{
	if (!ft_memcmp(line, "Sphere", 6))
	{
		line += 6;
		init_sphere(line, obj, e);
		return ;
	}
	else if (!ft_memcmp(line, "Plane", 5))
	{
		line += 5;
		init_plane(line, obj, e);
		return ;
	}
	else if (!ft_memcmp(line, "Cylinder", 8))
	{
		line += 8;
		init_cylinder(line, obj, e);
		return ;
	}
	object_type_option_quater(line, obj, e);
}

void	object_type_option_quater(char *line, t_obj *obj, t_env **e)
{
	if (!ft_memcmp(line, "Cone", 4))
	{
		line += 4;
		init_cone(line, obj, e);
		return ;
	}
	else
		syntax_error(e);
}

void	init_plane(char *line, t_obj *obj, t_env **e)
{
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{')
		line++;
	else
		syntax_error(e);
	obj->o_axis = create_vect(*e);
	object_ori_rot_final(line, e);
}

void	init_sphere(char *line, t_obj *obj, t_env **e)
{
	int	i;

	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{')
		line++;
	else
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	i = 0;
	while (!ft_isspace(*line) && *line != '}' && *line != '\0')
	{
		i++;
		line++;
	}
	line -= i;
	obj->rayon = ft_atoif(line);
	line += i;
	object_ori_rot_final(line, e);
}

void	init_cylinder(char *line, t_obj *obj, t_env **e)
{
	int	i;

	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line == '{')
		line++;
	else
		syntax_error(e);
	while (ft_isspace(*line) && *line != '\0')
		line++;
	i = 0;
	while (!ft_isspace(*line) && *line != '}' && *line != '\0')
	{
		i++;
		line++;
	}
	line -= i;
	obj->rayon = ft_atoif(line);
	obj->o_axis = create_vect(*e);
	line += i;
	object_ori_rot_final(line, e);
}
