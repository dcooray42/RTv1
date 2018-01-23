/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:36:47 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/07 08:47:48 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_param_bis(char *line, t_env **e)
{
	if (!ft_memcmp(line, "Object", 6) || (*e)->status == 3)
	{
		if ((*e)->status != 3)
		{
			init_object(e);
			line += 6;
		}
		object_settings(line, e);
		return (1);
	}
	else if (!ft_memcmp(line, "Light", 5) || (*e)->status == 4)
	{
		if ((*e)->status != 4)
		{
			init_light(e);
			line += 5;
		}
		light_settings(line, e);
		return (1);
	}
	return (check_param_ter(line, e));
}

int		check_param_ter(char *line, t_env **e)
{
	if (*line == '}' && (*e)->status == 1)
	{
		(*e)->status = 0;
		return (1);
	}
	else if (*line == '\0' && (*e)->status == 1)
		return (1);
	else
		return (0);
}

void	num_obj_light(t_env *e)
{
	t_list	*obj;
	t_list	*light;

	obj = e->list;
	light = e->light;
	while (obj)
	{
		e->n_obj++;
		obj = obj->next;
	}
	while (light)
	{
		e->n_light++;
		light = light->next;
	}
}

int		correct_number(char *str)
{
	while ((*str == ' ' || *str == '\t') && *str != '\0')
		str++;
	if ((*str == '+' || *str == '-') && *str != '\0')
		str++;
	while (ft_isdigit(*str) && *str != '\0')
		str++;
	if (*str == '.' && *str != '\0')
		str++;
	while (ft_isdigit(*str) && *str != '\0')
		str++;
	if (*str == '\0')
		return (1);
	else
		return (0);
}

double	change_value(char *str, t_env *e)
{
	int		i;
	char	*tmp;
	double	n;

	i = 1;
	while (i)
	{
		ft_printf("%s = ", str);
		get_next_line(0, &tmp);
		if (correct_number(tmp))
		{
			i = 0;
			n = ft_atoif(tmp);
			ft_strdel(&tmp);
		}
		else
			ft_printf("\nEnter a valid number\n");
		ft_printf("\n");
	}
	e->s2 = 0;
	return (n);
}
