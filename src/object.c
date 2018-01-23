/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:34:41 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/24 19:20:25 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_object(t_env **e)
{
	t_obj	*obj;
	t_list	*tmp;

	if ((obj = (t_obj *)ft_memalloc(sizeof(t_obj))) == NULL)
		malloc_error(e);
	obj->name = NULL;
	obj->status = 1;
	obj->rayon = 0.0;
	obj->k = 0.0;
	obj->t = 0.0;
	obj->clr = create_color(*e);
	obj->c = NULL;
	obj->abc = create_vect(*e);
	obj->origintoobj = create_vect(*e);
	obj->o_axis = NULL;
	if ((tmp = ft_lstnew(obj, sizeof(t_obj))) == NULL)
		malloc_error(e);
	ft_lstadd(&(*e)->list, tmp);
	ft_memdel((void **)&obj);
}

void	object_settings(char *line, t_env **e)
{
	if ((*e)->status == 1)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (*line == '{')
		{
			line++;
			(*e)->status = 3;
		}
		else
			syntax_error(e);
	}
	if ((*e)->status == 3)
	{
		while (ft_isspace(*line) && *line != '\0')
			line++;
		if (object_option(line, e))
			return ;
		else
			syntax_error(e);
	}
}

int		object_option(char *line, t_env **e)
{
	t_obj	*obj;

	obj = (t_obj *)(*e)->list->content;
	if (!ft_memcmp(line, "Name", 4) && obj->status == 1)
	{
		line += 4;
		while (ft_isspace(*line) && *line != '\0')
			line++;
		name_object(line, e);
		return (1);
	}
	else if (!ft_memcmp(line, "Inter", 5) || obj->status == 2)
	{
		if (!obj->name)
			syntax_error(e);
		if (obj->status != 2)
			line += 5;
		object_type(line, obj, e);
		return (1);
	}
	return (object_option_bis(line, e));
}

void	name_object(char *line, t_env **e)
{
	int		i;
	t_obj	*obj;

	obj = (t_obj *)(*e)->list->content;
	if (*line == '{' && !obj->name)
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
	if (!(obj->name = ft_strsub(line, 0, i)))
		malloc_error(e);
	line += i;
	while (ft_isspace(*line) && *line != '\0')
		line++;
	if (*line != '}')
		syntax_error(e);
}
